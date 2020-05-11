global m rho S g rxf rxr ryf rz r Iz
global Cx0 Cyb CR rk
global delta omega
global Klqr xeq

%% Variables definition

% Initial conditions
psi0 = 0/180*pi;
x0 = 0;
y0 = 0;

% System variables
g = 9.81; %gravity acceleration
rho = 1.225; %air density
S = 2.4; %cross surface
Cx0 = -0.3; %drag coefficient
Cyb = -0.03; %drag coefficient
rk = 1; %dry asphalt
m = 1200; %vehicle mass
V = 90/3.6; %vehicle speed

rxf = 1.4; %center-of-gravity to front axle
rxr = -1.6; %center-of-gravity to rear axle
ryf = 0.90; %center-of-gravity to y-wheel
rz = -0.70;
r = 0.28; %wheel radius
rx = [rxf rxf rxr rxr];
ry = [ryf -ryf -ryf ryf];

H = [ones(1,4); ry; -rx];
lf = sqrt(rxf^2+ryf^2); %center-of-gravity to front-wheels
lr = sqrt(rxr^2+ryf^2); %center-of-gravity to rear-wheels

CR = -0.05; %aerodynamic constant
Iz = 1200*(rxr^2+ryf^2)^2; %moment of inertia

LLf =   0.04; %friction related
omega_r = V/r; %rear wheels speed
omega_f = V/r/(1-LLf); %front wheels speed
omega = [omega_f; omega_f; omega_r; omega_r];
delta = 5*[1 1 0 0]/180*pi; %wheel-undervehicle angle

%% Linearization

% Linearisation of the friction coefficient
muL0 = 0;
lambda0 = 0;
muL0 = muL0+ partial_mu(rk,lambda0);

%Linearisation of the forces acting on the wheels
beta00 = 0;
w00 = 0;

FzW = (H'/(H*H'))*(0*rz/2*rho*S*V^2*[0; Cyb*beta00; Cx0]+[m*g; 0*rz*m*V*w00*cos(beta00); 0*rz*m*V*w00*sin(beta00)]);
Ff = FzW(1); %FzW(1)=FzW(2)
Fr = FzW(3); %FzW(3)=FzW(4)
Cf = 2*muL0*Ff; %front cornering stiffness
Cr = 2*muL0*Fr; %rear cornering stiffness

%Linearised matrices
a11 = -(Cf + Cr);
a12 = -(Cf*rxf + Cr*rxr)/(V);
a21 = -(Cf*rxf + Cr*rxr);
a22 = -(Cf*lf^2 + Cr*lr^2)/(V);
A = [(1/m*V)*a11, -1 + (1/m*V)*a12; (1/Iz)*a21, (1/Iz)*a22];

b1 = Cf;
b2 = Cf*rxf;
B1 = [(1/m*V)*b1; (1/Iz)*b2];

B2 = ryf*r/(2*Iz*V)*[zeros(1,4); -Cf, Cf, Cr, -Cr];

%Neutral steer point
s = (Cf*rxf+Cr*rxr)/(Cf+Cr);
if s > 0
    disp('OVERSTEERED VEHICLE')
    disp(['s = ',num2str(s),' meters'])
elseif s < 0
    disp('UNDERSTEERED VEHICLE')
    disp(['s = ',num2str(s),' meters'])
else
    disp('NEUTRAL STEERED VEHICLE')
end

% Equilibrium point
xeq = -inv(A)*B1*(delta(1)+delta(2)/2);

if abs(xeq(1)) > atan(0.02*1.3*g)
    xeq(1) = atan(0.02*1.3*g) * sign(xeq(1)); %Saturation value of slip angle
end
if abs(xeq(2)) > 0.85*1.3*g/V
    xeq(2) = 0.85*1.3*g/V * sign(xeq(2)); %Saturation value of yaw rate
end

disp('LINEAR EQUIIBRIUM POINT')
disp(['Slip angle beta = ',num2str(xeq(1)*180/pi),' degrees'])
disp(['Yaw rate omega = ',num2str(xeq(2)*180/pi),' degrees per seconds'])
