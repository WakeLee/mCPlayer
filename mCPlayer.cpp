#include "StdAfx.h"
#include "mCPlayer.h"

mCPlayer::mCPlayer(void)
{
}
mCPlayer::~mCPlayer(void)
{
}

void mCPlayer::CheckError(MCIERROR mciError)
{
	if(mciError)
	{
		WCHAR aError[1024] = {0};
		mciGetErrorString(mciError, aError, sizeof(aError));
		log(aError);
	}  
}

void mCPlayer::Open(CStringW sFile)
{
	ToAbsolutePath(sFile);

	m_paramOpen.lpstrDeviceType = L"mpegvideo";  
	m_paramOpen.lpstrElementName = sFile;  
	CheckError(mciSendCommand(0, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD)&m_paramOpen));
}
void mCPlayer::Close()
{
	CheckError(mciSendCommand(m_paramOpen.wDeviceID, MCI_CLOSE, 0, (DWORD)&m_paramPlay));
}

void mCPlayer::Play()
{
	CheckError(mciSendCommand(m_paramOpen.wDeviceID, MCI_PLAY, MCI_FROM, (DWORD)&m_paramPlay));
}
void mCPlayer::Pause()
{
	CheckError(mciSendCommand(m_paramOpen.wDeviceID, MCI_PAUSE, 0, (DWORD)&m_paramPlay));
}
