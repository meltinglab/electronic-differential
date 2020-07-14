# electronic-differential

The aim of this project is to develop the software for a Drive-by-wire Electronic differential Control board an test it on an Evaluation Board.

The developed system is intended to work on an electric sedan vehicle of medium dimensions, with 4 independent driving wheels, having one electric motor each.
The aim of the control system is to substitute the mechanical components transmitting power from a central engine to the wheels on traditional vehicles, directly controlling the wheels rotation by means of control signals produced by an electronic control unit. The control system shall also properly counteract the effects of slipping due to lack of friction on critical condition roads (e.g. icy road, wet asphalt, etc.).

The system, that combines the actions of both a mechanical differential and an ESP controller, must provide the correct wheel speed to each of the four wheels in order to safely follow the speed and trajectory intended by the driver and avoid lateral skidding despite the road/conditions inefficiencies. The overall task of the controller is thus to enhance the performance of the vehicle in normal driving conditions and increase the stability in critical and harsh case scenarios.



## 1. description of the model

The model’s blocks and subsystems are organized as depicted below.

![Image of overall model](https://github.com/meltinglab/electronic-differential/blob/master/reports/images/overall_model.png)

* The refence generator block is a block that generates the reference environment for the simulation of the car model; in this block it is possible to set the kind of the maneuver and related conditions. 
* The driver command is a block that, given as input the feedback of vehicle dynamics and the reference of the maneuver, provides as output the ratio of the throttle and brake pedals and the steering angle, simulating the behavior of a driver in a predictive way.
* In the control block there are all the electronic controls of the vehicle; in particular, given as input the command of the driver and the vehicle’s feedback, it manages the batteries and controls the motors and brakes. In this block, torque is set for ABS and ESP control.
* In the environmental block, all the parameters to simulate the interaction between the car and the environment are present.
* In the passenger vehicle block, there is the complete model of a standard electric sedan car. Inside it is split in two modules, interacting with each other:
  * The mechanical block, containing the models of the steering, the brake, the motors and the batteries;
  * The body block, modelling the chassis and the interaction with road.
  
 The control develop from scratch by our team is located in Control Block.


## 2. System requirements

The design has all been performed on Matlab/Simulink environment.
In order to interface with the developed model, the following software modules are required:
*	MATLAB R2019b and Simulink;
*	Powertrain Blockset;
*	Vehicle Dynamics Blockset.

To complete the PIL validation procedure, an additional software package is also required:
*	Embedded Coder Support Package for STMicroelectronics Discovery Boards.

Finally, the generated code has been deployed on a target board, requiring the following hardware:
*	STMicroelectronics STM32F4-Discovery board;
*	USB type A to Mini-B cable;
*	USB TTL-232 cable – TTL-232R 3.3V (serial communication for STM32F4-Discovery board).



## 3. Project organization

In software development, the V-model represents a development process that may be considered an extension of the waterfall model. Instead of moving down in a linear way, the process steps are bent upwards after the coding phase, to form the typical V shape. The V-Model demonstrates the relationships between each phase of the development process and its associated phase of testing and validation. The horizontal and vertical axes represent time, or project completeness, (left-to-right) and level of abstraction (coarsest-grain abstraction uppermost), respectively.
 
![Image of V-Model](https://github.com/meltinglab/electronic-differential/blob/master/reports/images/V_model.png)
 
The approach followed throughout all the development of the controller system described in this dissertation is well depicted by the above picture.

The development process starts from System Requirements phase, where a definition of the high-level system behavior is carried out, including all the requirements needed to obtain a high accuracy controller for the intended application. The successive step is the System Architectural Design, which comprehends the definition of the individual software modules for the controller, the development of the car model where to integrate the controller, the design of the verification process, and the deployment of the final validation phase on target hardware. Thus, Software Requirements definition is possible: a characterization of the structure of the ESP controller and the virtual differential system, with the definition of input and expected output values, as well as the physical equations (the physical model, indeed) that lie behind the behavior of the controllers, responsible for the desired performance, has been accomplished.

The two branches of the V-model are linked through a design phase in which developers must take care of Software design, its implementation and then its integration. In the project, Software Design has been represented by actual implementation on Matlab/Simulink of the software modules defined in the previous steps using both hand-written Matlab code and Simulink blocks. Then, Automatic Code Generation played a significant role in Software Implementation phase. Hence, the code was ready to be implemented on the target hardware, which has been properly configured.

Finally, verification and validation phases have been carried out. Firstly, controllers have been tested individually, by giving them specific input vectors and defining particular case scenarios in order to analyze their response and check whether their behaviors were correct or not (what can be called unit testing, preliminary Software Test run in Matlab environment on host computer). After that, the behavior of the controllers integrated with the car system has been checked; several tests have been performed on the integrated system (integration testing, System Integration Test still run on host computer), pushing the controller to work in different situations and with different parameters (making the car following several trajectories). Finally the last kind of testing, for the aim of the project and the resources available, has been accomplished: Software-In-the-Loop (SIL), with controller running on the host computer, and Processor-In-the-Loop (PIL), for which controllers are implemented on a target board, the STM32F4-Discovery. These two simulation tests highlighted the correspondence between the C code of the controller, generated by Matlab Embedded Code Generator (the automatic code generation tool), and the controller model.
Further tests could be possible such as on-field testing with a real car, and they should be performed before implementing the safety-critical system on a marketable vehicle, but they are out of scope for the purpose of this project.

The team organization is detailed describe in [Overall report](https://github.com/meltinglab/electronic-differential/blob/master/reports/Report-Project.docx) file



## 4. Related documents

All the development and validation files, together with the related reports detailing the design procedures, are stored on a repository on GitHub, which can be found at the url:
https://github.com/meltinglab/electronic-differential
Specifically, for more detailed documentation on the development and validation of the systems, some reference documents can be found under the reports directory:

* [Overall report](https://github.com/meltinglab/electronic-differential/blob/master/reports/Report-Project.docx): Introduces the project description including the project and team organization
*	[Car Model](https://github.com/meltinglab/electronic-differential/blob/master/reports/Report-CarModel.docx): introduces the Simulink model of the car, with which the developed control system is supposed to interact with.
* [Electronic Stability Program](https://github.com/meltinglab/electronic-differential/blob/master/reports/Report-ElectronicStabilityProgram.docx): describes the development and testing of the ESP controller unit.
* [Virtual Differential](https://github.com/meltinglab/electronic-differential/blob/master/reports/Report-VirtualDifferential.docx): describes the development and testing of the virtual differential controller unit.
* [Integration](https://github.com/meltinglab/electronic-differential/blob/master/reports/Report-Integration.docx): introduces the integration procedure and illustrates some tests performed on the integrated system.
* [Validation SIL and PIL](https://github.com/meltinglab/electronic-differential/blob/master/reports/Report-ValidationSILPIL.docx): describes the method used to validate the developed control system according to SIL and PIL validation processes.





-------------

----



##### Authors:

- Davide Capuzzo                      
- Federico Galli
- Alessandro Luppi                    








.
