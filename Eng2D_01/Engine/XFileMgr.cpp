#include "XFileMgr.h"
#include "XString.h"

namespace X
{
	FileManager GFileManager;

	void FileManager::init()
	{

	}

	void FileManager::release()
	{

	}

	bln FileManager::fileOpenReadFull( const char* filename, void* outFileContents, uint& outByteRead )
	{
		XASSERT(filename && outFileContents);
		outByteRead = 0;
		HANDLE hFile = ::CreateFileA(filename, GENERIC_READ, 0, nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
		if(hFile == INVALID_HANDLE_VALUE)
			return false;
		DWORD fSize = ::GetFileSize(hFile, nullptr);
		DWORD numRead = 0;
		if(fSize == INVALID_FILE_SIZE)
		{
			::CloseHandle(hFile);
			return false;
		}
		if(::ReadFile(hFile, outFileContents, fSize, &numRead, nullptr))
		{
			::CloseHandle(hFile);
			outByteRead = numRead;
			return true;
		}
		::CloseHandle(hFile);
		return false;
	}

	bln FileManager::fileCreateWriteFull( const char* fileName, const void* fileContents, size_t contentsSize, uint& outByteWritten)
	{
		XASSERT(fileName && fileContents);
		outByteWritten = 0;
		HANDLE hFile = ::CreateFileA(fileName, GENERIC_WRITE, 0, nullptr, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr);
		if(hFile == INVALID_HANDLE_VALUE)
			return false;
		DWORD dwWritten = 0;
		if(::WriteFile(hFile, fileContents, contentsSize, &dwWritten, nullptr));
		{
			::CloseHandle(hFile);
			outByteWritten = dwWritten;
			return true;
		}
		::CloseHandle(hFile);
		return false;
	}

	bln FileManager::fileDelete( const char* filename )
	{
		XASSERT(filename);
		return ::DeleteFileA(filename);
	}

	bln FileManager::fileGetSize( const char* filename, uint& outSize )
	{
		XASSERT(filename);
		outSize = 0;
		HANDLE hFile = ::CreateFileA(filename, GENERIC_READ, 0, nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
		if(hFile == INVALID_HANDLE_VALUE)
			return false;
		DWORD result = ::GetFileSize(hFile, nullptr);
		if(result == INVALID_FILE_SIZE)
		{
			::CloseHandle(hFile);
			return false;
		}
		::CloseHandle(hFile);
		outSize = result;
		return true;
	}

	uint FileManager::findFile( const char* pattern, FileInfo* outFiles )
	{
		XASSERT(pattern && outFiles);
		uint nFile = 0;
		WIN32_FIND_DATA findData;
		HANDLE hFind = ::FindFirstFile(pattern, &findData);
		if(hFind == INVALID_HANDLE_VALUE)
			return 0;
		do 
		{
			outFiles[nFile].size = findData.nFileSizeLow;
			StrCopy(outFiles[nFile].name, findData.cFileName);
			nFile++;
		} 
		while (::FindNextFileA(hFind, &findData));
		::FindClose(hFind);
		return nFile;
	}

};