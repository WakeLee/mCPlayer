#pragma once

#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

class mCPlayer
{
public:
	mCPlayer(void);
	~mCPlayer(void);

	MCI_OPEN_PARMS m_paramOpen;
	MCI_PLAY_PARMS m_paramPlay;

	void CheckError(MCIERROR mciError);

	void Open(CStringW sFile);
	void Close();

	void Play();
	void Pause();
};

