Game = {}
Game["initialize"] = function()
	print("Game Initialized")
	print("Press E to exit.")
end

Game["pause"] = function()
	print("Game has been paused.")
end

Game["resume"] = function()
	print("Game has resumed.")
end

Game["update"] = function()
	if tk.isKeyDown("A") then
		print("A pressed")
	elseif tk.isKeyDown("E") then
		tk.popState()
	end
end

Game["render"] = function()

end

MainMenu = {}
MainMenu["initialize"] = function()
	print("MainMenu Initialized")
	print("Press ESCAPE to exit. Press S to start the game.")
end

MainMenu["pause"] = function()
	print("MainMenu has been paused.")
end

MainMenu["resume"] = function()
	print("MainMenu has resumed.")
end

MainMenu["update"] = function()
	if tk.isKeyDown("S") then
		tk.pushState("Game")
	elseif tk.isKeyDown("ESCAPE") then
		tk.popState()
	end
end

MainMenu["render"] = function()

end



tk.pushState("MainMenu")