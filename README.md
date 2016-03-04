# StudentsProjectsApp
StudentsProjectsApp is a GUI application made with C++ and QT. It also uses SQLite as the database.

StudentsProjectsApp uses a database to store various information about projects that are available (for a certain class or school) and presents it in a GUI application for the user.  The user is able to login as a student or admin provided you have the correct username and password combination. 

The student users are able to view/leave projects they've already joined and join new projects which are created by the admins. Two sets of attributes(such as leadership, experience, organizational skills etc.) are also stored for each individual student, and they are able to be edited using the GUI. The first set is the students own ratings of themselves, and the other set is a set of rating them wish for in an ideal team. An algorithm will be added later that sorts students into teams based on a mixture of attributes.

The admin users are able to create, update, and edit the projects they own.