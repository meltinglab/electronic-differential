function dx = ESPSIM(t,x) %returns the derivative of x at time instant t
%All the parameters must be set

global m rho S g rxf rxr ryf rz r Iz
global Cx0 Cyb CR rk
global delta omega
global tmin tmax
global Klqr xeq CL ICE

rx = [rxf rxf rxr rxr];
ry = [ryf -ryf -ryf ryf];

LTR = 0.13; %Reference value for lambda we don't want to overcome

%State variables
px = x(1);
py = x(2);
V = x(3);
beta = x(4);
w = x(5);
psi = x(6);

FaB = 1/2*rho*S*V^2*[Cx0; Cyb*beta];

tauBi = zeros(1,4); %torque on the wheels
muBi = zeros(2,4); %vertical force coefficients

%Closed loop control
if CL == 1
    u = -Klqr*(x(4:5)-xeq);
end

%Forces on the 4 wheels
for i = 1:4
    deltai = delta(i); %wheel rotation
    ryi = ry(i); %wheel y position
    rxi = rx(i); %wheel x position
    VWi = [cos(deltai), sin(deltai); -sin(deltai), cos(deltai)]*(w*[-ryi; rxi]+V*[cos(beta); sin(beta)]); %wheel speed
    Vxi = VWi(1); %wheel speed along x
    Vyi = VWi(2); %wheel speed along y
    
    if i == 1 || i == 2 %front wheels
        wi = omega(i);
    end
    if i == 3 || i ==4 %rear wheels
        wi = Vxi/r;
    end
    
    %Apply control
    if CL == 1
        wi = wi + u(i);
        
        %Implementation of saturation logic
        if wi > Vxi/r %Driving condition
            a = 1-LTR^2;
            b = -2*Vxi;
            c = a*Vyi^2+Vxi^2;
            if b^2-4*a*c >= 0
                r_wr=roots([a b c]);
            else
                r_wr=roots([1 -Vxi -Vyi^2]);
            end
            wr = max(r_wr); %reference speed
            if wi > wr/r
                wi = wr/r;
            end
        end
        
        if wi < Vxi/r %Braking condition
            a = 1;
            b = -2*Vxi;
            c = (1-LTR^2)*(Vyi^2+Vxi^2);
            if b^2-4*a*c >= 0
                r_wr=roots([a b c]);
            else
                r_wr=Vxi;
            end
            wr = min(r_wr); %reference speed
            if wi < wr/r
                wi = wr/r;
            end
        end

    end
    
    if wi < 0
        wi = 0;
    end
    
    %Definition of slip ratio
    vmaxi = sqrt(Vyi^2 + (max(wi*r, Vxi))^2);
    LLi = (wi*r-Vxi)/vmaxi;
    LSi = (-Vyi)/vmaxi;
    LTi = sqrt(LLi^2 + LSi^2);
    
    if LTi == 0 %pure rolling
        muB = [cos(deltai), -sin(deltai); sin(deltai), cos(deltai)]*[CR; 0];
    else %skidding
        kind = rk;
        
        if (ICE == 1) && (t > max(tmin)) && (t < max(tmax))
            %kind = 2; %Driving on wet asphalt
            kind = 4; %Driving on ice
            %kind = 6; %Driving on wet cobblestone
        end
        
        muL = MuLong(kind,LTi);
        muB = [cos(deltai), -sin(deltai); sin(deltai), cos(deltai)]*[LLi/LTi*muL+CR; LSi/LTi*muL];
    end
    
    muBi(:,i) = muB;
    
    %Compute braking torque
    tauBi(i) = [(sin(deltai)*rxi - cos(deltai)*ryi), (cos(deltai)*rxi+sin(deltai)*ryi)]*muB;
end

b = [m*g; 0; 0]; %Result of the matrix in the FzW expression
arm_x = zeros(1,4);
arm_y = zeros(1,4);

for i = 1:4
    arm_x(i) = ry(i)-rz*muBi(2,i);
    arm_y(i) = -rx(i)+rz*muBi(1,i);
end

H = [1 1 1 1; arm_x; arm_y];
FzW=(H'/(H*H'))*b; %vertical forces on wheels

FB = FaB;
tauB = 0;

for i = 1:4
    FB = FB + muBi(:,i)*FzW(i); %forces on body
    tauB = tauB + tauBi(i)*FzW(i); %torques on body
end

%System definition
dp = [V*cos(psi+beta); V*sin(psi+beta)];

dV = [1/m, 0, 0; 0, 1/(m*V), 0; 0, 0, 1/Iz]*([cos(beta), sin(beta), 0; -sin(beta), cos(beta), 0; 0, 0, 1]*[FB; tauB]-[0; m*V; 0]*w);

dpsi = w;

dx = [dp; dV; dpsi];