# StudentsProjectsApp
StudentsProjectsApp is a GUI application made with C++ and QT. It also uses SQLite as the database.

To run in QT simply import a project and select the app.pro file that's included as the import file. Then clear project, run qmake option and compile.

StudentsProjectsApp uses a database to store various information about projects that are available (for a certain class or school) and presents it in a GUI application for the user.  The user is able to login as a student or admin provided you have the correct username and password combination. 

The admin users are able to create new projects and update/delete the projects they own.

The student users are able to view/leave projects they've already joined and join new projects. Two sets of attributes(such as leadership, experience, organizational skills etc.) are also stored for each individual student, and they are able to be edited using the GUI. The first set is the students own ratings of themselves, and the other set is a set of rating them wish for in an ideal team. The ratings are based on a scale from 1-10. An algorithm will be added later that sorts students into teams based on the mixture of attributes that fit together best.

List of registered users:
Admin1
Admin2
Admin3
Alice
Bob
Charlie
Peter
Susan

All passwords are currently set to 'p' for testing purposes.



