SELECT runs.id,day,locations.name,run_types.name,surfaces.name,shoes.name,shoes.brand AS Date
    FROM runs
    INNER JOIN locations
		ON locations.id=runs.location_id
	INNER JOIN run_types
		ON run_types.id=runs.runtype_id
	INNER JOIN surfaces
		ON surfaces.id=runs.surface_id
	INNER JOIN shoes
		ON shoes.id=runs.shoe_id
    WHERE day<=2458563 AND day>=2458520
    ORDER BY day ASC