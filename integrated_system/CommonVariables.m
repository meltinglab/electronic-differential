%   CommonVariables
% This file contains variables that are common between files.
%
% The introduced variables are parameterized using meaningful names.
% You may use one or more variables simply calling the variable name.
% You must avoid the introduction of other variables sharing the name with
% one of the variables here defined. Thus, please check carefully each
% variable introduced by this file and avoid any override.
%
%
%
% USAGE:
% ----------------
% In a Matlab file:
%   simply call 'CommonVariables'
%   
%   example of use:
%       
%       % Introduce common variables
%       CommonVariables
%       
%       % Introduce specific variables
%       my_var = 10;
% ----------------
% In a Simulink file:
%   move to Modelling > Design > Property Inspector
%   under the 'Properties' page, look for 'Callbacks'
%   select either 'PostLoadFcn', 'InitFcn' or 'StartFcn'
%   call the CommonVariables file in the white space below
%
%   see https://www.mathworks.com/help/simulink/ug/model-callbacks.html
%   for more hints on which callback function to select
% ----------------
%
%
%
% If you want to contribute to this file, open it and read the section
% below 'How to Contribute'


% %%%%%%%%%%%%%%%%%%%%%%%%%
% How to Contribute
%
% This file should define vehicle parameters that are useful to other
% systems defined in different files (e.g. model of differential; file for
% validation of ESP controller).
%
% When you add a variable, you should give it a meaningful name
%   ex: mass_wheel or massWheel to indicate the mass of a single wheel
%
% You should add a comment in the line above indicating the meaning of the
% variable, and an inline comment speficying the unit of measure; in
% absence of different agreements, you shall use SI units of measure; you
% may set a variable to NaN and ask vehicle owner to properly set it
%
% When you add a new variable, you must inform the owner of the vehicle
% model, who must adjust the model with the newly added parameter
%
%
% See existing variables for reference
% %%%%%%%%%%%%%%%%%%%%%%%%%


%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% vehicle body parameters
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% 

%%
% Vehicle parameters

% Forward location of tire, a [m]:
VEH.FrontAxlePositionfromCG = 1.515000000000000
% Rearward location of tire, b [m]:
VEH.RearAxlePositionfromCG = 1.504000000000000
% wheel to wheel distance [m]:
VEH.wheel_to_wheel = 1.80
%height of center of mass [m]:
VEH.center_of_mass =-0.70
% Vehicle mass, m [kg]:
VEH.Mass = 1181
% Track hardpoint coordinates relative to axle center, TrackCoords [m]
VEH.TrackWidth = 1.9220
% Vertical distance from center of mass to axle plane, h [m]
VEH.HeightCG = 0.1340
% Initial position in inertial frame [Xeo,Yeo,Zeo], Xe_o [m]:
VEH.InitialLongPosition = 0
VEH.InitialLatPosition = 3.1250
VEH.InitialVertPosition = 0
% Initial velocity in body axes [xdot_o,ydot_o,zdot_o], xbdot_o [m/s]:
VEH.InitialLongVel = 0
VEH.InitialLatVel = 0
VEH.InitialVertVel = 0
%Initial Euler orientation [roll, pitch, yaw], eul_o [rad]:
VEH.InitialRollAngle = 0
VEH.InitialPitchAngle = 0
VEH.InitialYawAngle = 0
%Initial body rotation rates [p,q,r], p_o [rad/s]
VEH.InitialRollRate = 0
VEH.InitialPitchRate = 0
VEH.InitialYawRate = 0
%Chassis inertia tensor, Iveh [kg*m^2]
VEH.RollMomentInertia = 1.9227e+03
VEH.PitchMomentInertia = 432.3333
VEH.YawMomentInertia = 2066
% Longitudinal drag area, Af [m^2]:
VEH.FrontalArea = 2.1100
% Wheel radius, [m]
VEH.WheelRadius = 0.31;
% max speed [m/s]
VEH.MaxSpeed = 160/3.6;


% Suspension
% block: solid axis suspension (Coil spring)
% Axle and wheels lumped principal moment of inertia about longitudinal axis, AxlIxx [kg*m^2]
AxlIxx = 62.37451666666666
% Axle and wheels lumped mass, AxlM [kg]:
AxlM = 160
% Wheel and axle interface compliance constant, KzWhlAxl [N/m]
KzWhlAxl = 138031.6120778669 
% Wheel and axle interface compliance preload, F0zWhlAxl [N]
F0zWhlAxl = 2907
% Wheel and axle interface damping constant, CzWhlAxl [Ns/m]
CzWhlAxl = 11490.97125702646
% Suspension spring constant, Kz [N/m]
Kz = 52451.00657928319
% Suspension spring preload, F0z [N]:
F0z = [2886 2907]
% Suspension shock damping constant, Cz [Ns/m]
Cz = 5565.224643801984
% Suspension maximum height, Hmax [m]
Hmax =0.25
% Vehicle Adapter
h = 0.134


%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% vehicle mechanics parameters
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% 

% Litium ion battery pack
% Rated capacity at nominal temperature, BattChargeMax [Ah]:
BattChargeMax = 32.5
% Open circuit voltage table data, Em [V]:
Em = [2.8 3.228 3.284 3.361 3.408 3.427 3.472 3.477 3.493 3.504 3.516 3.528 3.537 3.545 3.555 3.561 3.566 3.576 3.587 3.589 3.594 3.6 3.608 3.61 3.616 3.619 3.626 3.632 3.637 3.64 3.645 3.646 3.652 3.655 3.658 3.661 3.664 3.668 3.673 3.678 3.68 3.681 3.686 3.692 3.699 3.702 3.705 3.71 3.717 3.723 3.728 3.733 3.735 3.742 3.749 3.755 3.761 3.768 3.773 3.78 3.791 3.798 3.798 3.814 3.818 3.825 3.841 3.846 3.855 3.863 3.877 3.885 3.894 3.907 3.919 3.926 3.935 3.944 3.954 3.964 3.974 3.988 3.998 4.014 4.029 4.034 4.047 4.065 4.074 4.086 4.097 4.131 4.126 4.138 4.15 4.18 4.174 4.187 4.207 4.231 4.221]
% Open circuit voltage breakpoints 1, CapLUTBp []:
CapLUTBp = [0 0.01 0.02 0.03 0.04 0.05 0.06 0.07 0.08 0.09 0.1 0.11 0.12 0.13 0.14 0.15 0.16 0.17 0.18 0.19 0.2 0.21 0.22 0.23 0.24 0.25 0.26 0.27 0.28 0.29 0.3 0.31 0.32 0.33 0.34 0.35 0.36 0.37 0.38 0.39 0.4 0.41 0.42 0.43 0.44 0.45 0.46 0.47 0.48 0.49 0.5 0.51 0.52 0.53 0.54 0.55 0.56 0.57 0.58 0.59 0.6 0.61 0.62 0.63 0.64 0.65 0.66 0.67 0.68 0.69 0.7 0.71 0.72 0.73 0.74 0.75 0.76 0.77 0.78 0.79 0.8 0.81 0.82 0.83 0.84 0.85 0.86 0.87 0.88 0.89 0.9 0.91 0.92 0.93 0.94 0.95 0.96 0.97 0.98 0.99 1]
% Internal resistance table data, RInt [Ohms]:
RInt = [0.008846 0.009319 0.009027 0.00847 0.01032 0.01314;0.006389 0.006554 0.005553 0.005525 0.006043 0.007805;0.004364 0.004101 0.00406 0.003452 0.003846 0.004517;0.002031 0.002563 0.002532 0.00246 0.002716 0.003047;0.001443 0.001825 0.001795 0.001778 0.001924 0.002234;0.0005603 0.0007192 0.0006887 0.0007557 0.0007355 0.001014;0.001028 0.001338 0.001 0.001536 0.001546 0.002789]
% Battery temperature breakpoints 1, BattTempBp [K]:
BattTempBp = [243.1 253.1 263.1 273.1 283.1 298.1 313.1]
% Battery capacity breakpoints 2, CapSOCBp []:
CapSOCBp = [0 0.2 0.4 0.6 0.8 1]
% Number of cells in series, Ns []
Ns = 96
% Number of cells in parallel, Np []:
Np = 2
% Initial battery capacity, BattCapInit [Ah]:
BattCapInit =26

% motors
% Torque control time constant, Tc, [s]:
Tc = 0.02
% Maximum torque, torque_max [Nm]:
torque_max = 280
% Maximum power, power_max [W]:
power_max = 30000
%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% control  
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%

% Battery control
% max battery charge
BattChrgMax = -80000
% max battery discharge
BattDischrgMax = 80000
% charge limiting
ChrgLmt_bpt = [1 1 1 1 1 1 1 1 0.7 0.35 0]
% discharge limiting
DischrgLmt_bpt= [0 0.35 0.7 1 1 1 1 1 1 1 1]
SOC_bpt = [0 10 20 30 40 50 60 70 80 90 100]

% Breake control
% Converts Brake Pedal Position to Brake Pressure Request
BrkPrsMax = 5000000

% trottle control
% Accelerator Pedal Position to Torque Command 
MotSpd = [0 1000 2000 2728.370453 3000 4000 5000 6000 7000 8000 9000 10000]
MotTrq = [280 280 280 280 254.6479089 190.9859317 152.7887454 127.3239545 109.1348181 95.49296586 84.88263632 76.39437268]

% reginerative breaking
% MotTrqReflectedToWheels
Ndiff = 7.94
RegenBrkCutOff = [0 1]
RegenBrkSpd_bpt = [5 9]
% 4*(mu_kinetic*pi*disk_abore^2*Rm*num_pads/4)
Rm = 0.15
Rs = 0.2
disk_abore = 0.05
mu_kinetic = 0.35
num_pads = 2

%power management
efficiency_table = [85 85 85 85 85 85 85 85 85 85 85 85 85 85 85;85 85 85 85 85 85 85 85 85 85 85 85 85 85 85;85 85 90 90 90 90 90 90 90 90 88 88 88 88 88;85 85 92 92 92 92 92 92 92 92 92 90 90 90 90;85 85 92 92 93 93 93 93 92 92 92 90 90 90 90;85 85 93 94 94 94 94 94 94 94 94 94 94 94 94;85 85 93 94 94 95 95 95 95 95 95 95 95 95 95;85 85 93 94 94 95 95 95 95 95 95 95 95 95 95;85 85 93 94 95 95 95 95 95 95 95 95 95 95 95;85 85 93 94 95 95 95 95 95 95 95 95 95 95 95;85 85 93 94 94 94 94 94 94 94 94 94 94 94 94;85 85 90 92 93 93 93 93 93 93 93 93 93 93 93]
% (break point)
T_eff_bp = [0 20 40 60 80 100 120 140 160 180 200 220 240 260 280]
w_eff_bp =[0 1000 2000 2728.370453 3000 4000 5000 6000 7000 8000 9000 10000]


DLCXref=[0 7 9 18 33.5 34 42 50 60]
DLCYref=[0 0 -4.5 -4 -3.75 1.25 0.75 0 0]


