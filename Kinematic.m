function Kinematic(theta1, theta2, length1, length2) %Takes the 
%parameters Joint angle1, Joint angle 2,Link length 1 and link length 2 for
%the @-link robot arm.
%sym x1 x2 y1 y2;

%% Dynamic calculation

theta1 = theta1 * pi/180; %to convert into degrees
theta2 = theta2 * pi/180; %to convert into degrees

x1=length1*cos(theta1); %x coordinate of link2
y1=length1*sin(theta1); %y coordinate of link2 

x2= x1 + length2*cos(theta1 + theta2);
y2= y1 + length2*sin(theta1 + theta2);

%% Plotting the graph or the UI for the figure.

%Origin
O= [0 0];
%axis = [gca, 'equal']; %Set aspect ratio
axis([-5.0 5.0 -5.0 5.0]); %plot limit
grid on; %enable grid

%Set the ground
ground1 = line([0 -5], [-4.98 -4.98],'Color','black');
set(ground1,'LineWidth',4); % makes to an appropriate depth

ground2 = line([0 0], [-5 0],'Color','black');
set(ground2,'LineWidth',4); % makes to an appropriate depth
%Circle in the origin
O_circ= viscircles(O, 0.05, 'Color','b');

%Line plotted for link display
link1 = line([0 x1]  , [0 y1] , 'Color','red');
set(link1,'LineWidth',2); % makes to an appropriate depth

%Circle at the joint 1
%O_circ= viscircles([x1 y1], 0.05);
O_circ1 = viscircles([x1 y1], 0.05,'Color','b');

%Drawing the second link
link2 = line([x1 x2], [y1 y2],'Color','red');
set(link2,'LineWidth',2);


%The point for the end effector
O_circ1 = viscircles([x2 y2], 0.05,'Color','b');


%Plot the graph //For debugging
%plot([x1 y1], [x2 y2]);

%plot([0 0]  , [x1 y1]);
%plot([x1 y1], [x2 y2]);
end