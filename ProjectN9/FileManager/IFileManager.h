//
//  IFileManager.h
//  ProjectN6
//
//  Created by pc-laptop on 10/24/18.
//  Copyright © 2018 Ingrid Guerrero. All rights reserved.
//

#pragma once

namespace FileSystem
{
    typedef void *FileObject;
    
    enum FileType
    {
        FileTypeRead,
        FileTypeWrite,
    };
    
    class TFile
    {
    private:
        FileObject m_FileObject;
        const char *m_fileName;
        
    public:
        TFile();
        ~TFile();
        FileObject GetFileObject();
        bool OpenFile (const char *fileName, FileType fileType);
        void CloseFile ();
        unsigned int ReadFile (char *pReadCharacterBuffer, unsigned int uNumOfCharacters);
        unsigned int WriteFile (char *pWriteCharacterBuffer, unsigned int uNumOfCharacters);
    };
}


