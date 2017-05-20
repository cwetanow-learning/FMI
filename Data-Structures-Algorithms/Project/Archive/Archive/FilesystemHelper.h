/**
*
* Solution to homework task
* Data Structures Course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Ivan Mladenov
* @idnumber 91650
* @task
* @compiler VC>
*
*/

#include <fstream>
#include <iostream>
#include <string>

#include "DynamicQueue.cpp"

using namespace std;

#pragma once
class FilesystemHelper
{
private:
	// Get the size of a file
	std::streampos GetFileSize(const char* filePath);

public:
	FilesystemHelper();
	~FilesystemHelper();

	// Combines several files into one
	void SaveToFile(string path, DynamicQueue<string> files, string outFile);

	// Restores combined files
	void RestoreDirectory(string compressedDirectory, string targetDirectory);

	// Reads a directory and puts all its files into a queue
	void TraverseDirectory(string path, string folder, DynamicQueue<string>& files);
};

