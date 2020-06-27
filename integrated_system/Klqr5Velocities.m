%% Variables definition

% Initial conditions
psi0 = 0/180*pi;
x0 = 0;
y0 = 0;

% System variables
g = 9.81; %gravity acceleration
rho = 1.225; %air density
S = VEH.FrontalArea; %cross surface
Cx0 = -0.3; %drag coefficient
Cyb = -0.03; %drag coefficient
rk = 1; %dry asphalt
m = 1200; %vehicle mass

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

LLf =   0.04; %friction related | 0.0003 

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
w00 = 0;

%Definition of the optimization function
Q = inv(2*diag([(0.2/180*pi)^2 (1/180*pi)^2])); %set Q matrix
R = inv(4*eye(4)*(40*(2*pi)/60)^2); %set R matrix

%% V1 50km/h

V1 = 50/3.6;
FzW = (H'/(H*H'))*(0*rz/2*rho*S*V1^2*[0; Cyb*beta00; Cx0]+[m*g; 0*rz*m*V1*w00*cos(beta00); 0*rz*m*V1*w00*sin(beta00)]); %vertical force on the wheels
Ff = FzW(1); %FzW(1)=FzW(2)
Fr = FzW(3); %FzW(3)=FzW(4)
Cf = 2*muL0*Ff; %front cornering stiffness
Cr = 2*muL0*Fr; %rear cornering stiffness

%Linearised matrices
a11 = -(Cf + Cr);
a12 = -m*V1-(Cf*rxf + Cr*rxr)/(V1);
a21 = -(Cf*rxf + Cr*rxr);
a22 = -(Cf*lf^2 + Cr*lr^2)/(V1);
A = [1/(m*V1) 0;0 1/Iz]*[a11, a12; a21, a22];
A_1 = A;

b1 = Cf;
b2 = Cf*rxf;
B1_1 = [1/(m*V1) 0;0 1/Iz]*[b1; b2];

B2 = ryf*r/(2*Iz*V1)*[zeros(1,4); -Cf, Cf, Cr, -Cr];

[Klqr1,Sinfty,eigACL] = lqr(A,B2,Q,R);


%% V2 70km/h

V2 = 70/3.6;
FzW = (H'/(H*H'))*(0*rz/2*rho*S*V2^2*[0; Cyb*beta00; Cx0]+[m*g; 0*rz*m*V2*w00*cos(beta00); 0*rz*m*V2*w00*sin(beta00)]); %vertical force on the wheels
Ff = FzW(1); %FzW(1)=FzW(2)
Fr = FzW(3); %FzW(3)=FzW(4)
Cf = 2*muL0*Ff; %front cornering stiffness
Cr = 2*muL0*Fr; %rear cornering stiffness

%Linearised matrices
a11 = -(Cf + Cr);
a12 = -m*V2-(Cf*rxf + Cr*rxr)/(V2);
a21 = -(Cf*rxf + Cr*rxr);
a22 = -(Cf*lf^2 + Cr*lr^2)/(V2);
A = [1/(m*V2) 0;0 1/Iz]*[a11, a12; a21, a22];
A_2 = A;

b1 = Cf;
b2 = Cf*rxf;
B1_2 = [1/(m*V2) 0;0 1/Iz]*[b1; b2];

B2 = ryf*r/(2*Iz*V2)*[zeros(1,4); -Cf, Cf, Cr, -Cr];

[Klqr2,Sinfty,eigACL] = lqr(A,B2,Q,R);


%% V3 90km/h

V3 = 90/3.6;
FzW = (H'/(H*H'))*(0*rz/2*rho*S*V3^2*[0; Cyb*beta00; Cx0]+[m*g; 0*rz*m*V3*w00*cos(beta00); 0*rz*m*V3*w00*sin(beta00)]); %vertical force on the wheels
Ff = FzW(1); %FzW(1)=FzW(2)
Fr = FzW(3); %FzW(3)=FzW(4)
Cf = 2*muL0*Ff; %front cornering stiffness
Cr = 2*muL0*Fr; %rear cornering stiffness

%Linearised matrices
a11 = -(Cf + Cr);
a12 = -m*V3-(Cf*rxf + Cr*rxr)/(V3);
a21 = -(Cf*rxf + Cr*rxr);
a22 = -(Cf*lf^2 + Cr*lr^2)/(V3);
A = [1/(m*V3) 0;0 1/Iz]*[a11, a12; a21, a22];
A_3 = A;

b1 = Cf;
b2 = Cf*rxf;
B1_3 = [1/(m*V3) 0;0 1/Iz]*[b1; b2];

B2 = ryf*r/(2*Iz*V3)*[zeros(1,4); -Cf, Cf, Cr, -Cr];

[Klqr3,Sinfty,eigACL] = lqr(A,B2,Q,R);


%% V4 110km/h

V4 = 110/3.6;
FzW = (H'/(H*H'))*(0*rz/2*rho*S*V4^2*[0; Cyb*beta00; Cx0]+[m*g; 0*rz*m*V4*w00*cos(beta00); 0*rz*m*V4*w00*sin(beta00)]); %vertical force on the wheels
Ff = FzW(1); %FzW(1)=FzW(2)
Fr = FzW(3); %FzW(3)=FzW(4)
Cf = 2*muL0*Ff; %front cornering stiffness
Cr = 2*muL0*Fr; %rear cornering stiffness

%Linearised matrices
a11 = -(Cf + Cr);
a12 = -m*V4-(Cf*rxf + Cr*rxr)/(V4);
a21 = -(Cf*rxf + Cr*rxr);
a22 = -(Cf*lf^2 + Cr*lr^2)/(V4);
A = [1/(m*V4) 0;0 1/Iz]*[a11, a12; a21, a22];
A_4 = A;

b1 = Cf;
b2 = Cf*rxf;
B1_4 = [1/(m*V4) 0;0 1/Iz]*[b1; b2];

B2 = ryf*r/(2*Iz*V4)*[zeros(1,4); -Cf, Cf, Cr, -Cr];

[Klqr4,Sinfty,eigACL] = lqr(A,B2,Q,R);


%% V5 130km/h

V5 = 130/3.6;
FzW = (H'/(H*H'))*(0*rz/2*rho*S*V5^2*[0; Cyb*beta00; Cx0]+[m*g; 0*rz*m*V5*w00*cos(beta00); 0*rz*m*V5*w00*sin(beta00)]); %vertical force on the wheels
Ff = FzW(1); %FzW(1)=FzW(2)
Fr = FzW(3); %FzW(3)=FzW(4)
Cf = 2*muL0*Ff; %front cornering stiffness
Cr = 2*muL0*Fr; %rear cornering stiffness

%Linearised matrices
a11 = -(Cf + Cr);
a12 = -m*V5-(Cf*rxf + Cr*rxr)/(V5);
a21 = -(Cf*rxf + Cr*rxr);
a22 = -(Cf*lf^2 + Cr*lr^2)/(V5);
A = [1/(m*V5) 0;0 1/Iz]*[a11, a12; a21, a22];
A_5 = A;

b1 = Cf;
b2 = Cf*rxf;
B1_5 = [1/(m*V5) 0;0 1/Iz]*[b1; b2];

B2 = ryf*r/(2*Iz*V5)*[zeros(1,4); -Cf, Cf, Cr, -Cr];

[Klqr5,Sinfty,eigACL] = lqr(A,B2,Q,R);

