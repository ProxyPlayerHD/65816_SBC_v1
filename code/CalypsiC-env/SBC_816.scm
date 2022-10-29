(define memories'(
	(memory DirectPage	(address (#x000100 . #x0001FF))
		(section (registers ztiny)))
	(memory LoRAM	(address (#x000200 . #x00FEFF))
		(section stack))
	(memory IO		(address (#x010000 . #x0100FF)))
	(memory LoROM	(address (#x00FF00 . #x00FFFF)))
	(memory HiROM	(address (#x010100 . #x013FFF)))
	(memory HiRAM	(address (#x020000 . #x0FFFFF)) (type ANY)
		(section heap znear))
	(memory HiDB	(address (#x020000 . #x02FFFF)))
	(memory VRAM	(address (#xFF0000 . #xFFFFFF)))
	(block stack	(size #x001000))
	(block heap		(size #x008000))
	(base-address _DirectPageStart DirectPage 0)
	(base-address _NearBaseAddress HiDB 0)
))
