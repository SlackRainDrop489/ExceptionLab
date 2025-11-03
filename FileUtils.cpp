//
// Created by Christopher Vaughn on 10/29/25.
//
/**
 * @file FileUtils.cpp
 * @brief Implements utility functions for handling file operations.
 *
 * @author Quinn Alvine
 * @date 10/31/25
 * @version 1.0
 */

#include "FileUtils.h"
#include "Exceptions.h"     // Include for student's custom exceptions
#include <iostream>         // For cout, cerr, cin
#include <string>           // For string
#include <fstream>          // For ifstream

using namespace std;

/**
 * @brief Attempts to open a file, handling failures and retries.
 * * This function contains the logic that the student must
 * convert to use try...catch with FileOpenException.
 *
 * @param file The ifstream object to be opened (passed by reference).
 * @param initialFilename The first filename to try.
 */
void openFileForReading(std::ifstream &file, std::string initialFilename) {
	// STUDENT TODO: Replace the following 'if' block with a
	// try...catch block that throws and catches a FileOpenException.
	try {
		file.open(initialFilename); // This will try to open the file sent in in the begining
		if (!file.is_open()) { // This will look to see if the file was not opened
			throw FileOpenException("File could not be opened: " + initialFilename); // If the file was not opened then it will throw a FileOperException
		}
		cout << "File opened successfully: " << initialFilename << endl;
	} catch (const FileOpenException &e) { // This will catch the FileOpenException and run this code
		cout << e.what() << endl; // This will print out the error

		// This logic should be inside your 'catch' block
		string alternativeFilename;
		cout << "Enter alternative filename: "; // This will ask for another file
		cin >> alternativeFilename;
		file.open(alternativeFilename); // This will again try and open a new file

		if (!file.is_open()) { // This will check to see if the file failed to open
			cerr << "Error: Failed to open alternative file. Exiting." << endl; // If it did it will print out an error
			// In a real program, you might throw a PersistentFileError here,
			// but for this lab, we will just exit.
			exit(1); // Then the program will exit
		}
		cout << "Alternative file opened successfully: " << alternativeFilename << endl;
	}
}