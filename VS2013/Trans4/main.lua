print("Hello world")

t = {}
t["initialize"] = function()
	print("t Initialized")
end

t["update"] = function()
	if tk.isKeyDown("A") then
		print("A pressed")
	elseif tk.isKeyDown("ESCAPE") then
		tk.popState()
	end
end

t["render"] = function()

end

tk.pushState("t")