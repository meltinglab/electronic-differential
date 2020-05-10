%% Initialization

% Symbolic variables related to rotational elements
syms wi wc wp1 wf1 w1 wp2 wf2 w2                % angular speeds
syms ti tc tp1 tf1 t1 tp2 tf2 t2                % torques
syms Ji Jc Jp1 Jf1 J1 Jp2 Jf2 J2                % inertias
syms bi bc bp1 bf1 b1 bp2 bf2 b2                % rotational frictions

% Symbolic variables related to translational elements
syms F_ic1 F_c2p1_1 F_1p2_1 F_c2p1_2 F_1p2_2    % forces
syms K_ic1 K_c2p1_1 K_1p2_1 K_c2p1_2 K_1p2_2    % elasticities
syms b_ic1 b_c2p1_1 b_1p2_1 b_c2p1_2 b_1p2_2    % linear frictions

% Symbolic variables related to gears
syms ri rc1 rc2 rp1 rp2 rf r12                  % gear radii
syms zi zc1 zc2 zp1 zp2 zf z12                  % gear number of teeth

% Symbolic variables related to clutch frictions
syms b_clutch1 b_clutch2


%% Original system

% System matrices
J = diag([Ji Jc Jp1 Jf1 J1 Jp2 Jf2 J2]);             % Inertias
Bj = diag([bi bc bp1 bf1 b1 bp2 bf2 b2]);            % Rotational frictions
K = diag([K_ic1 K_c2p1_1 K_1p2_1 K_c2p1_2 K_1p2_2]); % Stifnesses
Bk = diag([b_ic1 b_c2p1_1 b_1p2_1 b_c2p1_2 b_1p2_2]);% Linear frictions

% Matrix of radii
R = [ -ri   -rc1      0      0      0      0      0      0
        0    rc2    rp1    -rf      0      0      0      0
        0      0    rp2    -rf    r12      0      0      0
        0    rc2      0      0      0    rp1    -rf      0
        0      0      0      0      0    rp2    -rf    r12 ];


% States, inputs, outputs
x_init = [wi wc wp1 wf1 w1 wp2 wf2 w2 ...
          F_ic1 F_c2p1_1 F_1p2_1 F_c2p1_2 F_1p2_2].';   % State vector
u_init = [ti tc tp1 tf1 t1 tp2 tf2 t2].';               % Input vector
y_init = [wi wc wp1 wf1 w1 wp2 wf2 w2].';               % Output vector

% POG state space matrices (initial)
Li = [ J,                               zeros(size(J,1), size(K,2)) ;
       zeros(size(J,1), size(K,2)).',                       inv(K)  ];
Ai = [ -Bj-R.'*Bk*R                   R.' ;
                  R      zeros(size(K,1)) ];
Bi = [eye(size(J,1));    zeros(size(J,1),size(K,2)).'];
Ci = Bi.';
Di = zeros(size(Ci,1));
Li=sym(Li);Ai=sym(Ai);Bi=sym(Bi);Ci=sym(Ci);Di=sym(Di);


% Consider friction system

% tf1 = b_clutch1 * wf1, with b_clutch1 depending on clutch pressure
% tf2 = b_clutch2 * wf2, with b_clutch2 depending on clutch pressure

% Delete tf1 and tf2 from inputs
del_el = find(u_init=='tf1' | u_init=='tf2');
keep_el = setdiff(1:length(u_init), del_el);
u = u_init(keep_el);
Bi = Bi(:,keep_el);
Di = Di(:,keep_el);

% Add b_clutch1*wf1 and b_clutch2*wf2 to states
Ai(del_el(1),del_el(1)) = Ai(del_el(1),del_el(1)) + b_clutch1;
Ai(del_el(2),del_el(2)) = Ai(del_el(2),del_el(2)) + b_clutch2;


% POG state space equations
fprintf('\n\nL*x_dot = \n')
disp(Ai*x_init + Bi*u)
fprintf('\n\ny = \n')
disp(Ci*x_init + Di*u)


%% Reduced system

% POG congruent transformation when K -> infinite
x = [wi,w1,w2].';     % new (reduced) state vector
eqn = R*x_init(1:length(u_init));
Sol = solve(eqn==0, [wc, wp1, wf1, wp2, wf2]);
Tx = equationsToMatrix([wi,Sol.wc,Sol.wp1,Sol.wf1,w1,Sol.wp2,Sol.wf2,w2,...
                        0,0,0,0,0], x);

% Reduced POG state space model
L = simplify(Tx.'*Li*Tx);
A = simplify(Tx.'*Ai*Tx);
B = simplify(Tx.'*Bi);
C = simplify(Ci*Tx);
D = Di;                     % not affected

% Reduced POG state space equations
fprintf('\n\nx_dot = \n')
disp(simplify(A*x + B*u))
fprintf('\n\ny = \n')
disp(simplify(C*x + D*u))


%% Differential case system


%% Combination of models


