#pragma once

namespace clio {
	enum class Key;

	
	/// The Keyboard interface allows you to query the current state of the keyboard.	
	class Keyboard {
	public:
		virtual ~Keyboard() {}

		/// Check if a key is being held down.
		///
		/// \param key The key to check for
		///
		/// \return true if the key is being held down, false otherwise.		
		virtual bool isKeyDown(Key key) = 0;
		
		/// No copying allowed.		
		Keyboard(Keyboard const&) = delete;
		
		/// No copying allowed.		
		Keyboard & operator=(Keyboard const&) = delete;
	protected:
		/// \brief Constructor.
		Keyboard() {}
	};
}