MapState = {}
MapState["initialize"] = function()
	tileset = tk.loadTexture("tileset.bmp")
	grass = tk.Rectangle(5*16+5, 0, 16, 16)
	dirt = tk.Rectangle(6*16+6, 0, 16, 16)
	
	map = { 
		{1,1,0,0,0,0,0,0,0,0},
        {0,1,0,0,0,0,0,0,0,0},
        {0,1,0,0,0,0,0,0,0,0},
        {1,1,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0}
    }
end

MapState["update"] = function()

end

MapState["render"] = function()
	for i = 1, 10 do
        for j = 1, 10 do
            local newPos = map[i][j]
            if newPos == 0 then
				tk.drawClip(tileset, j*16, i*16, grass.x, grass.y, grass.w, grass.h)
            elseif newPos == 1 then
				tk.drawClip(tileset, j*16, i*16, dirt.x, dirt.y, dirt.w, dirt.h)
			end
        end
    end
end

tk.pushState("MapState")