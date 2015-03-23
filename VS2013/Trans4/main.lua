print("Hello world")

t = {}
t["initialize"] = function()
	print("t Initialized")
	tex = tk.loadTexture("cold_weather.bmp")
end

t["update"] = function()
	if tk.isKeyDown("A") then
		print("A pressed")
	elseif tk.isKeyDown("ESCAPE") then
		tk.popState()
	end
end

t["render"] = function()
	tk.drawTexture(tex, 10, 10)
end

tk.pushState("t")