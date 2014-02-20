#pragma once

#include <string>
#include "fmod/fmod.hpp"
#include "SoundManager.h"

namespace T3D{

	class Music
	{
	friend class SoundManager;
	public:
		Music(SoundManager* sm);
		~Music(void);

		void play();	
		void pause();
		void stop();
		void setVolume(float v);	
		bool isPlaying();

	private:
		SoundManager* soundManager;
		FMOD::Sound *theMusic;
		FMOD::Channel *channel;

		float volume;
	};
}

