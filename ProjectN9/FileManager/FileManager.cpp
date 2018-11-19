//
//  FileManager.cpp
//  ProjectN6
//
//  Created by pc-laptop on 10/24/18.
//  Copyright © 2018 Ingrid Guerrero. All rights reserved.
//

#include <stdio.h>
#include "IFileManager.h"
#include "FileUtils.h"

FileSystem::TFile::TFile ()
{
    m_FileObject = nullptr;
}

FileSystem::TFile::~TFile ()
{
    CloseFile();
    m_fileName = nullptr;
    m_FileObject = nullptr;
}

FileSystem::FileObject FileSystem::TFile::GetFileObject()
{
    return m_FileObject;
}

bool FileSystem::TFile::OpenFile(const char *fileName, FileType fileType)
{
    m_fileName = fileName;
    m_FileObject = fopen(fileName, FileSystemUtils::GetFileNameType(fileType));
    
    if (m_FileObject == nullptr)
    {
        return false;
    }
    
    return true;
}

void FileSystem::TFile::CloseFile ()
{
    if (m_FileObject)
    {
        fclose(FileSystemUtils::GetFileObject(m_FileObject));
    }
}

unsigned int FileSystem::TFile::ReadFile (char *pReadCharacterBuffer, unsigned int uNumOfCharacters)
{
    return static_cast<unsigned int>(fread(pReadCharacterBuffer,
                                           1,
                                           uNumOfCharacters,
                                           FileSystemUtils::GetFileObject(m_FileObject)));
    
}

unsigned int FileSystem::TFile::WriteFile (char *pWriteCharacterBuffer, unsigned int uNumOfCharacters)
{
    return static_cast<unsigned int>(fwrite(pWriteCharacterBuffer,
                                            1,
                                            uNumOfCharacters,
                                            FileSystemUtils::GetFileObject(m_FileObject)));
}
