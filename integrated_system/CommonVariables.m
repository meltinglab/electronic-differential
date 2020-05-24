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
% CURRENT VARIABLES you should not override:
%
%   M_car           [kg]:       mass of the car (wheels exluded)
%   axle_length     [m] :       length of the axle
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
% Finally, you must add the variable name, together with a short
% description, to the help of the file, under the section CURRENT VARIABLES
%
% When you add a new variable, you must inform the owner of the vehicle
% model, who must adjust the model with the newly added parameter
%
%
% See existing variables for reference
% %%%%%%%%%%%%%%%%%%%%%%%%%



% Total mass of the vehicle sitting on suspensions, that is the global
% mass of the car excluding wheels' mass.
M_car = NaN;                % kg


% Front and rear axles' length. It corresponds to the distance between
% (rear or front) wheels in the connection points to axle.
axle_length = NaN;          % m

