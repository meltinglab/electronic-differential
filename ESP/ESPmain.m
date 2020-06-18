global m rho S g rxf rxr ryf rz r Iz
global Cx0 Cyb CR rk
global delta omega
global tmin tmax
global Klqr xeq CL ICE
%Klqr = gain from optimal control
%xeq = state equilibrium point
%CL = 0 -> open loop, CL = 1 -> closed loop
%ICE = 0 -> no ice*, ICE = 1 -> ice* is present 
%(*or something similar that alters the condition of the road)

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
V = 90/3.6; %vehicle speed | 50

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

LLf = 0.04; %friction related | 0.0003 
omega_r = V/r; %rear wheels speed
omega_f = V/r/(1-LLf); %front wheels speed
omega = [omega_f; omega_f; omega_r; omega_r];
delta = 5*[1 1 0 0]/180*pi; %wheel-undervehicle angle | 3.5 or 10

%% Linearization

% Linearisation of the friction coefficient around lambda0 = 0
muL0 = 0;
lambda0 = 0;
for j = 1:4
    muL0 = muL0+ PartialMu(j,lambda0);
end
muL0 = muL0/4;  %mean mu @ lambda0 = 0, average among 4 road types

%Linearisation of the forces acting on the wheels
beta00 = 0;
% beta00 = -0.0088;
w00 = 0;
% w00 = 0.3739;

FzW = (H'/(H*H'))*(0*rz/2*rho*S*V^2*[0; Cyb*beta00; Cx0]+[m*g; 0*rz*m*V*w00*cos(beta00); 0*rz*m*V*w00*sin(beta00)]); %vertical force on the wheels
Ff = FzW(1); %FzW(1)=FzW(2)
Fr = FzW(3); %FzW(3)=FzW(4)
Cf = 2*muL0*Ff; %front cornering stiffness
Cr = 2*muL0*Fr; %rear cornering stiffness

%Linearised matrices
a11 = -(Cf + Cr);
a12 = -m*V-(Cf*rxf + Cr*rxr)/(V);
a21 = -(Cf*rxf + Cr*rxr);
a22 = -(Cf*lf^2 + Cr*lr^2)/(V);
A = [1/(m*V) 0;0 1/Iz]*[a11, a12; a21, a22];

b1 = Cf;
b2 = Cf*rxf;
B1 = [1/(m*V) 0;0 1/Iz]*[b1; b2];

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
xeq = -inv(A)*B1*(delta(1)+delta(2))/2;

if abs(xeq(2)) > 0.85*1.3*g/V
    xeq(2) = 0.85*1.3*g/V * sign(xeq(2)); %Saturation value of yaw rate
end
if abs(xeq(1)) > atan(0.02*1.3*g)
    xeq(1) = atan(0.02*1.3*g) * sign(xeq(1)); %Saturation value of slip angle
end

disp('LINEAR EQUIIBRIUM POINT')
disp(['Slip angle beta = ',num2str(xeq(1)*180/pi),' degrees'])
disp(['Yaw rate omega = ',num2str(xeq(2)*180/pi),' degrees per seconds'])

%% System and Control

Q = inv(2*diag([(0.2/180*pi)^2 (1/180*pi)^2])); %set Q matrix
R = inv(4*eye(4)*(40*(2*pi)/60)^2); %set R matrix

[Klqr,Sinfty,eigACL] = lqr(A,B2,Q,R); %find optimal gain

disp('- LQR GAIN');
disp(-Klqr);
 
beta0 = xeq(1); 
w0 = xeq(2);

%% Open Loop simulation

tspan = [0 10];
tmin = max(tspan)/3 -1;
tmax = max(tspan)/3 +1;
options = odeset('MaxStep',0.01); %simulation options

CL = 0; %closed loop = false
ICE = 0; %ice* is not present
[t,y] = ode23(@ESPSIM,tspan,[x0; y0; V; beta0; w0; psi0],options);
ICE = 1; %ice* is present
[tICE,yICE] = ode23(@ESPSIM,tspan,[x0; y0; V; beta0; w0; psi0],options);

figure(1)

subplot(3,1,1)
plot(tICE, yICE(:,3)*3.6,'r')
%plot(t, y(:,3)*3.6,'r')
title('V [km/h]')
grid on

subplot(3,1,2)
plot(tICE, yICE(:,4)*180/pi,'r')
%plot(t, y(:,4)*180/pi,'r')
title('\beta [deg]')
grid on

subplot(3,1,3)
plot(tICE, yICE(:,5)*180/pi,'r')
%plot(t, y(:,5)*180/pi,'r')
title('\omega_z [deg/s]')
grid on
xlabel('TIME [s]')


figure(2)

plot(y(:,1),y(:,2),'b')
hold on
plot(yICE(:,1),yICE(:,2),'r')
grid on
xlabel('North [m]')
ylabel('West [m]')

%% ESP Control simulation

CL = 1; %closed loop control
ICE = 0; %ice* is not present
[tCL,yCL] = ode23(@ESPSIM,tspan,[x0; y0; V; beta0; w0; psi0],options);
ICE = 1; %ice* is present
[tCLICE,yCLICE] = ode23(@ESPSIM,tspan,[x0; y0; V; beta0; w0; psi0],options);

figure(1)

subplot(3,1,1)
hold on
plot(tCLICE, yCLICE(:,3)*3.6,'m')
%plot(tCL, yCL(:,3)*3.6,'m')
minV = min(min(min(yCLICE(:,3)) ,min(yCL(:,3))), min(min(yICE(:,3)), min(y(:,3))) );
maxV = max(max(max(yCLICE(:,3)) ,max(yCL(:,3))), max(max(yICE(:,3)), max(y(:,3))) );
plot([max(tmin) max(tmin)],[minV maxV]*3.6,'--k')
plot([max(tmax) max(tmax)],[minV maxV]*3.6,'--k')
text(max(tmin)*1.10,1.10*minV*3.6,'LOW FRICTION')
legend('OPEN LOOP','ESP')
grid on

subplot(3,1,2)
hold on
plot(tCLICE, yCLICE(:,4)*180/pi,'m')
plot(tCLICE, xeq(1)*180/pi.*ones(1,length(tCLICE)),'g')
%plot(tCL, yCL(:,4)*180/pi,'m')
%plot(tCL, xeq(1)*180/pi.*ones(1,length(tCL)),'g')
minB = min(min(min(yCLICE(:,4)) ,min(yCL(:,4))), min(min(yICE(:,4)), min(y(:,4))) );
maxB = max(max(max(yCLICE(:,4)) ,max(yCL(:,4))), max(max(yICE(:,4)), max(y(:,4))) );
plot([max(tmin) max(tmin)],[minB maxB]*180/pi,'--k')
plot([max(tmax) max(tmax)],[minB maxB]*180/pi,'--k')
text(max(tmin)*1.10,1.10*minB*180/pi,'LOW FRICTION')
legend('OPEN LOOP','ESP','ESP_{REF}')
grid on

subplot(3,1,3)
hold on
plot(tCLICE, yCLICE(:,5)*180/pi,'m')
plot(tCLICE, xeq(2)*180/pi.*ones(1,length(tCLICE)),'g')
%plot(tCL, yCL(:,5)*180/pi,'m')
%plot(tCL, xeq(2)*180/pi.*ones(1,length(tCL)),'g')
minW = min(min(min(yCLICE(:,5)) ,min(yCL(:,5))), min(min(yICE(:,5)), min(y(:,5))) );
maxW = max(max(max(yCLICE(:,5)) ,max(yCL(:,5))), max(max(yICE(:,5)), max(y(:,5))) );
plot([max(tmin) max(tmin)],[minW maxW]*180/pi,'--k')
plot([max(tmax) max(tmax)],[minW maxW]*180/pi,'--k')
text(max(tmin)*1.10,1.10*minW*180/pi,'LOW FRICTION')
legend('OPEN LOOP','ESP','ESP_{REF}')
grid on


figure(2)

hold on
plot(yCL(:,1),yCL(:,2),'c')
hold on
plot(yCLICE(:,1),yCLICE(:,2),'m')
grid on
VL = 4;
tsamp = round(length(tCLICE)/3):10:length(tCLICE);
quiver(yCLICE(tsamp,1),yCLICE(tsamp,2),VL*cos(yCLICE(tsamp,6)),VL*sin(yCLICE(tsamp,6)),'k','AutoScale','off')
tsamp = round(length(tICE)/3):10:length(tICE);
quiver(yICE(tsamp,1),yICE(tsamp,2),VL*cos(yICE(tsamp,6)),VL*sin(yICE(tsamp,6)),'k','AutoScale','off')
Strt=min(find(tCLICE > tmin));
End =max(find(tCLICE < tmax));
plot(yCLICE(Strt,1),yCLICE(Strt,2),'kd')
plot(yCLICE(End,1),yCLICE(End,2),'kd')
plot(yICE(Strt,1),yICE(Strt,2),'kd')
plot(yICE(End,1),yICE(End,2),'kd')
legend('OPEN LOOP','OPEN LOOP ICE','ESP','ESP ICE')

%Control burden
u = -Klqr*(yCLICE(:,4:5)'-[ones(length(tCLICE),1)*xeq(1) ones(length(tCLICE),1)*xeq(2)]');
wi = zeros(4,length(tCLICE));
%Plot result for each wheel
for i = 1:4
    for j = 1:length(tCLICE)
        
        deltai = delta(i);  %wheel rotation
        ryi = ry(i); %wheel y position
        rxi = rx(i); %wheel x position
        
        VWi = [cos(deltai), sin(deltai); -sin(deltai), cos(deltai)]*(yCLICE(j,5)*[-ryi; rxi]+yCLICE(j,3)*[cos(yCLICE(j,4)); sin(yCLICE(j,4))]); %wheel speed
        Vxi = VWi(1); %wheel speed along x
        Vyi = VWi(2); %wheel speed along y
        
        if i == 1 || i == 2 %front wheels
            wi(i,j) = omega(i);
        end
        if i == 3 || i ==4 %rear wheels
            wi(i,j) = Vxi/r;
        end
        
        %Apply control
        if CL == 1
            wi(i,j) = wi(i,j)+ u(i,j);
            
            %Logical deactivation of ESP
            if wi(i,j) < Vxi/r*(1-0.13) %if BRAKING
                wi(i,j) = Vxi/r*(1-0.13);
            end
            
            if wi(i,j) > Vxi/r/(1-0.13) %if DRIVING
                wi(i,j) = Vxi/r/(1-0.13);
            end
            
        end
        
        if wi(i,j) < 0
            wi(i,j) = 0;
        end
        
    end
end

figure(3)

subplot(2,2,1)
plot(tCLICE,wi(1,:)*60/(2*pi))
hold on
minV = min(wi(1,:));
maxV = max(wi(1,:));
plot([max(tmin) max(tmin)],[minV maxV]*60/(2*pi),'--k')
plot([max(tmax) max(tmax)],[minV maxV]*60/(2*pi),'--k')
text(max(tmin)*1.10,1.10*minV*180/pi,'LOW FRICTION')
xlabel('TIME [s]')
ylabel('Wheel speed [RPM]')
title('FRONT LEFT')
grid on

subplot(2,2,2)
plot(tCLICE,wi(2,:)*60/(2*pi));
hold on
minV = min(wi(2,:));
maxV = max(wi(2,:));
plot([max(tmin) max(tmin)],[minV maxV]*60/(2*pi),'--k')
plot([max(tmax) max(tmax)],[minV maxV]*60/(2*pi),'--k')
text(max(tmin)*1.10,1.10*minV*60/(2*pi),'LOW FRICTION')
xlabel('TIME [s]')
ylabel('Wheel speed [RPM]')
grid on
title('FRONT RIGHT')

subplot(2,2,3)
plot(tCLICE,wi(4,:)*60/(2*pi))
hold on
minV = min(wi(4,:));
maxV = max(wi(4,:));
plot([max(tmin) max(tmin)],[minV maxV]*60/(2*pi),'--k')
plot([max(tmax) max(tmax)],[minV maxV]*60/(2*pi),'--k')
text(max(tmin)*1.10,1.10*minV*60/(2*pi),'LOW FRICTION')
xlabel('TIME [s]')
ylabel('Wheel speed [RPM]')
grid on
title('REAR LEFT')

subplot(2,2,4)
plot(tCLICE,wi(3,:)*60/(2*pi))
hold on
minV = min(wi(3,:));
maxV = max(wi(3,:));
plot([max(tmin) max(tmin)],[minV maxV]*60/(2*pi),'--k')
plot([max(tmax) max(tmax)],[minV maxV]*60/(2*pi),'--k')
text(max(tmin)*1.10,1.10*minV*60/(2*pi),'LOW FRICTION')
xlabel('TIME [s]')
ylabel('Wheel speed [RPM]')
grid on
title('REAR RIGHT')


figure(4)

subplot(2,2,1)
plot(tCLICE,u(1,:)*60/(2*pi))
hold on
minV = min(u(1,:));
maxV = max(u(1,:));
plot([max(tmin) max(tmin)],[minV maxV]*60/(2*pi),'--k')
plot([max(tmax) max(tmax)],[minV maxV]*60/(2*pi),'--k')
text(max(tmin)*1.10,1.10*minV*60/(2*pi),'LOW FRICTION')
xlabel('TIME [s]')
ylabel('Control law [RPM]')
grid on
title('FRONT LEFT')

subplot(2,2,2)
plot(tCLICE,u(2,:)*60/(2*pi))
hold on
minV = min(u(2,:));
maxV = max(u(2,:));
plot([max(tmin) max(tmin)],[minV maxV]*60/(2*pi),'--k')
plot([max(tmax) max(tmax)],[minV maxV]*60/(2*pi),'--k')
text(max(tmin)*1.10,1.10*minV*60/(2*pi),'LOW FRICTION')
xlabel('TIME [s]')
ylabel('Control law [RPM]')
grid on
title('FRONT RIGHT')

subplot(2,2,3)
plot(tCLICE,u(4,:)*60/(2*pi))
hold on
minV = min(u(4,:));
maxV = max(u(4,:));
plot([max(tmin) max(tmin)],[minV maxV]*60/(2*pi),'--k')
plot([max(tmax) max(tmax)],[minV maxV]*60/(2*pi),'--k')
text(max(tmin)*1.10,1.10*minV*60/(2*pi),'LOW FRICTION')
xlabel('TIME [s]')
ylabel('Control law [RPM]')
grid on
title('REAR LEFT')

subplot(2,2,4)
plot(tCLICE,u(3,:)*60/(2*pi))
hold on
minV = min(u(3,:));
maxV = max(u(3,:));
plot([max(tmin) max(tmin)],[minV maxV]*60/(2*pi),'--k')
plot([max(tmax) max(tmax)],[minV maxV]*60/(2*pi),'--k')
text(max(tmin)*1.10,1.10*minV*60/(2*pi),'LOW FRICTION')
xlabel('TIME [s]')
ylabel('Control law [RPM]')
grid on
title('REAR RIGHT')