print("Hello world")

t = {}
t["initialize"] = function()
	print("t Initialized")
	tex = tk.loadTexture("cold_weather.bmp")
	
	r = tk.Rectangle(10, 10, 500, 500)
	print(r.x)
	print(r.w)
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
	tk.drawClip(tex, 500, 500, 50, 50, 180, 100)
end

tk.pushState("t")