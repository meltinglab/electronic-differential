%% Retrieve gain variable

% Execute function to retrieve control matrix
Klqr5Velocities

% Close eventual figures and clear command window
close all
clc


%% Assert control gain is correct to move vehicle toward a stable state


% % % Behavioural tests % % %

% Assert action at equilibrium condition
[contr_magn, contr_sign] = ControlAction(0,0,1);
assert(contr_magn < 0.01, 'Error at equilibrium condition')

% Assert action with small positive yaw rate error
[contr_magn, contr_sign] = ControlAction(0,0.2,2);
assert(contr_magn > 0.01 && contr_magn < 1000, ...
        'Error with small positive yaw rate')
assert(contr_sign < 0, ...
        'Error with small positive yaw rate')

% Assert action with big positive yaw rate error
[contr_magn, contr_sign] = ControlAction(0,2,3);
assert(contr_magn > 100, ...
        'Error with big positive yaw rate')
assert(contr_sign < 0, ...
        'Error with small positive yaw rate')

% Assert action with small negative yaw rate error
[contr_magn, contr_sign] = ControlAction(0,-0.2,4);
assert(contr_magn > 0.01 && contr_magn < 1000, ...
        'Error with small negative yaw rate')
assert(contr_sign > 0, ...
        'Error with small negative yaw rate')

% Assert action with big negative yaw rate error
[contr_magn, contr_sign] = ControlAction(0,-2,5);
assert(contr_magn > 100, ...
        'Error with big negative yaw rate')
assert(contr_sign > 0, ...
        'Error with small negative yaw rate')

% Assert action with small positive heading error
[contr_magn, contr_sign] = ControlAction(0.2,0,1);
assert(contr_magn > 0.01 && contr_magn < 1000, ...
        'Error with small positive heading')
assert(contr_sign > 0, ...
        'Error with small positive heading')

% Assert action with big positive heading error
[contr_magn, contr_sign] = ControlAction(2,0,2);
assert(contr_magn > 100, ...
        'Error with big positive heading')
assert(contr_sign > 0, ...
        'Error with big positive heading')

% Assert action with small negative heading error
[contr_magn, contr_sign] = ControlAction(-0.1,0,3);
assert(contr_magn > 0.01 && contr_magn < 1000, ...
        'Error with small negative heading')
assert(contr_sign < 0, ...
        'Error with small negative heading')

% Assert action with big negative heading error
[contr_magn, contr_sign] = ControlAction(-1,0,4);
assert(contr_magn > 100, ...
        'Error with big negative heading')
assert(contr_sign < 0, ...
        'Error with big negative heading')

% Assert action with both errors
[contr_magn, contr_sign] = ControlAction(1.3,1.3,5);
assert(contr_magn > 0.01, 'Error with control action')
[contr_magn, contr_sign] = ControlAction(-0.5,-0.5,1);
assert(contr_magn > 0.01, 'Error with control action')


% % % Symmetric behaviour tests % % %

% Test of opposite conditions
[contr_magn1, contr_sign1] = ControlAction(0.3,-4,2);
[contr_magn2, contr_sign2] = ControlAction(-0.3,4,2);
assert(abs(contr_magn1-contr_magn2) < 0.01, 'Error in symmetry test')
assert(contr_sign1+contr_sign2 == 0, 'Error in symmetry test')

[contr_magn1, contr_sign1] = ControlAction(1.2,0.4,3);
[contr_magn2, contr_sign2] = ControlAction(-1.2,-0.4,3);
assert(abs(contr_magn1-contr_magn2) < 0.01, 'Error in symmetry test')
assert(contr_sign1+contr_sign2 == 0, 'Error in symmetry test')

[contr_magn1, contr_sign1] = ControlAction(23,-51,4);
[contr_magn2, contr_sign2] = ControlAction(-23,51,4);
assert(abs(contr_magn1-contr_magn2) < 0.01, 'Error in symmetry test')
assert(contr_sign1+contr_sign2 == 0, 'Error in symmetry test')


% % % Stress tests % % %

% Test with heading error of pi/2, -pi/2, pi, >pi
[contr_magn, contr_sign] = ControlAction(pi/2,0,5);
assert(contr_magn > 100, 'Error in heading stress test')
assert(contr_sign > 0, 'Error in heading stress test')

[contr_magn, contr_sign] = ControlAction(-pi/2,0,1);
assert(contr_magn > 100, 'Error in heading stress test')
assert(contr_sign < 0, 'Error in heading stress test')

% [contr_magn, contr_sign] = ControlAction(pi,0,2);
% assert(contr_magn < 10, 'Error in heading stress test')
% 
% [contr_magn, contr_sign] = ControlAction(-pi,0,3);
% assert(contr_magn < 10, 'Error in heading stress test')
% 
% [contr_magn, contr_sign] = ControlAction(10*pi,0,4);
% assert(contr_magn < 1000, 'Error in heading stress test')

% Test with yaw rate error very high
[contr_magn, contr_sign] = ControlAction(0,100,5);
assert(contr_magn > 10, 'Error in yaw rate stress test')
assert(contr_sign < 0, 'Error in yaw rate stress test')

% Test with yaw rate error very high
[contr_magn, contr_sign] = ControlAction(0,-200,1);
assert(contr_magn > 10, 'Error in yaw rate stress test')
assert(contr_sign > 0, 'Error in yaw rate stress test')


% % % Tests completed % % %
fprintf('Checks completed, control action validated.\n')


%% Create a function to test sign and magnitude of total control action
function [contr_magn, contr_sign] = ControlAction(delta_b, delta_w, gain_number)
    global Klqr1 Klqr2 Klqr3 Klqr4 Klqr5
    
    switch gain_number
        case 1
            Klqr = Klqr1;
        case 2
            Klqr = Klqr2;
        case 3
            Klqr = Klqr3;
        case 4
            Klqr = Klqr4;
        case 5
            Klqr = Klqr5;
    end
    
    % Compute control action
    contr_action = -Klqr * [delta_b; delta_w];
    
    % Consider wheels' rotation effect on vehicle rotation
    contr_action = contr_action.*[-1;+1;+1;-1];
    
    % Get one total action (it reflects torque on vehicle)
    complete_action = sum(contr_action);
    
    % Get magnitude and sign of control action
    contr_magn=abs(complete_action);
    contr_sign=sign(complete_action);
end




