
//Header files allow us to put declarations in one location and then import them 
//wherever we need them. This can save a lot of typing in multi-file programs.

//When you #include a file, the content of the included file is inserted at the 
//point of inclusion. This provides a useful way to pull in declarations from another file.

//Best practice: Header files should generally not contain function and variable definitions, 
//so as not to violate the one definition rule. An exception is made for symbolic constants.

//If a header file is paired with a code file (e.g. add.hh with add.cc), 
//they should both have the same base name (add).

//It’s common that a header file will need a declaration or definition that 
//lives in a different header file. Because of this, header files will 
//often #include other header files.These additional header files are sometimes 
//called “transitive includes”, as they’re included implicitly rather than explicitly.
//Best Practice: Each file should explicitly #include all of the header files it 
//needs to compile. Do not rely on headers included transitively from other headers.


// 1) We really should have a header guard here, but will omit it for simplicity (we'll cover header guards in the next lesson)

// 2) This is the content of the .h file, which is where the declarations go
int add(int x, int y); // function prototype for add.hh -- don't forget the semicolon!


