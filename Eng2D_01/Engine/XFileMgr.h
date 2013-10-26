#pragma once

#include "XArray.h"

namespace X
{
	static const uint MAX_FILE_NAME = 256;

	struct FileInfo
	{
		uint	size;
		char	name[MAX_FILE_NAME];
	};


	//////////////////////////////////////////////////////////////////////////FileManager
	class FileManager
	{
	public:

		void init();
		void release();

		bln fileOpenReadFull(const char* filename, void* outFileContents, uint& outByteRead);
		bln fileCreateWriteFull(const char* fileName, const void* fileContents, size_t contentsSize, uint& outByteWritten);
		bln fileDelete(const char* filename);
		bln fileGetSize(const char* fileName, uint& outSize);


		uint findFile(const char* pattern, FileInfo* outFiles);

		void finFileStart(char* patern);
		bln  findFile(FileInfo* outResult);
	};

	extern FileManager GFileManager;
};