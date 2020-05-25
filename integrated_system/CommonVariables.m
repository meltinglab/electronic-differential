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
%   wheel_base      [m]:        distance between front and rear axles
%   wheel_radius    [m]:        radius of a single wheel
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



% Wheel Base. It is the distance between front and rear axles of the
% vehicle (WhlBase in kinematic steering block)
wheel_base = (1.515+1.504);     % m


% Wheel radius. It is the half size of a single wheel. All the wheels are
% considered to be equal
wheel_radius = NaN;             % m

