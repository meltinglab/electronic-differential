%% Retrieve gain variable
global Klqr

% Execute function to retrieve control matrix
ESPmain

% Close figures
close all
clc

% Now gain matrix is available for tests
disp('- LQR GAIN');
disp(-Klqr);


%% Assert control gain is correct to move vehicle toward a stable state

[contr_magn, contr_sign] = ControlAction(0.1,0)


%% Create a function to test sign and magnitude of total control action
function [contr_magn, contr_sign] = ControlAction(delta_b, delta_w)
    global Klqr
    
    contr_action = -Klqr * [delta_b; delta_w];
    
    contr_action = contr_action.*[-1;+1;+1;-1];
    
    complete_action = sum(contr_action);
    
    contr_magn=abs(complete_action);
    contr_sign=sign(complete_action);
end




