#ifndef  _TELE_CONTROLLER_H_
#define _TELE_CONTROLLER_H_

class Television;

class TeleController
{
public:
	void VolumeUp(Television& tv);

	void VolumeDown(Television& tv);

	void ChanelUp(Television& tv);

	void ChanelDown(Television& tv);
};

#endif // _TELE_CONTROLLER_H_