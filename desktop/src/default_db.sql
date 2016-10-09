-- sql script to create an empty default atleto file
-- WORK IN PROGRESS !!
-- $Id: default_db.sql 366 2010-06-04 21:16:57Z boffyflow $

CREATE TABLE athletes 
(
    id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
    name varchar(255), 
    username varchar(255), 
    password varchar(255), 
    dob date,
    height float,                     -- height is in meters          
    male boolean,
    created_at datetime,              -- currently not used      
    updated_at datetime               -- currently not used
);

CREATE TABLE journal_entries
(
    id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
    day INTEGER NOT NULL,
    entry TEXT, 
    created_at  datetime,             -- currently not used
    updated_at  datetime              -- currently not used
);

CREATE TABLE locations
(		
    id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
    name varchar(255),
    created_at datetime,
    updated_at datetime
);

CREATE TABLE pace_zones
(
-- all times in seconds
    id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
    pzi INTEGER,
    race3K_max FLOAT,
    race3K_min FLOAT,
    race5K_max FLOAT,
    race5K_min FLOAT,
    race10K_max FLOAT,
    race10K_min FLOAT,
    pz1_max FLOAT,
    pz1_min FLOAT,
    pz2_max FLOAT,
    pz2_min FLOAT,
    pz3_max FLOAT,
    pz3_min FLOAT,
    pz4_max FLOAT,
    pz4_min FLOAT,
    pz5_max FLOAT,
    pz5_min FLOAT,
    pz6_max FLOAT,
    pz6_min FLOAT,
    pz7_max FLOAT,
    pz7_min FLOAT,
    pz8_max FLOAT,
    pz8_min FLOAT,
    pz9_max FLOAT,
    pz9_min FLOAT,
    pz10_max FLOAT,
    pz10_min FLOAT
);

CREATE TABLE physicals
(
    id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, 
    day_id integer,         -- not used/obosolete
    hr integer,             -- heart rate in bpm
    weight float,           -- in grams !
    bodyfat integer,        -- in promille !
    rating integer,         -- on a scale of 1 to 5 (0 is unknown)
    created_at datetime,    -- currently not used
    updated_at datetime,    -- currently not used
    day integer			    -- julian day
);

CREATE TABLE plots
(
    id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
    name TEXT,
    type INTEGER,
    y1data INTEGER,
    y2data INTEGER,
    aggregation INTEGER
);

CREATE TABLE pz_names
(
    pz INTEGER NOT NULL,
    name VARCHAR(50),
    gray_zone INTEGER NOT NULL DEFAULT "0" ,
    PRIMARY KEY(pz)
);

CREATE TABLE graphs
(
    id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
    name TEXT,
    xmldata TEXT
);

CREATE TABLE run_divisions
(
    id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
    name varchar(255), 
    created_at datetime,		-- currently not used
    updated_at datetime			-- currently not used
);

CREATE TABLE run_races
(   
    id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
    run_id integer,
    bib varchar(255),
    pl_overall integer,
    pl_division integer,
    num_overall integer, 
    num_division integer, 
    guntime float,              -- in seconds
    chiptime float,             -- in seconds
    division varchar(255), 
    name varchar(255),
    created_at datetime,        -- currently not used
    updated_at datetime         -- currently not used
);

CREATE TABLE run_splits
(
    id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
    run_id integer,             
    dist float,                 -- distance in meters
    t float,                    -- time in seconds
    hr integer,                 -- heartrate in bpm
    notes text,
    created_at datetime,        -- currently not used
    updated_at datetime         -- currently not used
);

CREATE TABLE run_types
(
    id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
    name varchar(255),
    created_at datetime,
    updated_at datetime
);

CREATE TABLE runs
(
    id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
    day_id integer,                 -- not used/obosolete
    location_id integer,
    surface_id integer,
    runtype_id integer,
    shoe_id integer,
    starttime time,
    endtime time,
    rating integer,                 -- on a scale of 1 to 5 (0 is unknown)
    indoors boolean,
    notes text,
    created_at datetime,            -- currently not used
    updated_at datetime,            -- currently not used
    day int,                        -- julian day
    device_file string              -- name of device file relative to data file
);

CREATE TABLE settings
(
    id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
    name varchar(255),
    base varchar(255),
    current varchar(255),
    created_at datetime,            -- currently not used
    updated_at datetime             -- currently not used
);

CREATE TABLE shoes
(
    id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
    name varchar(255),
    notes text,
    inuse boolean,
    created_at datetime,            -- currently not used
    updated_at datetime,            -- currently not used
    start_use  date,
    end_use  date,
    brand varchar(255),
    model varchar(255),
    size  varchar(255),
    start_mileage float,            -- in meters
    max_mileage  float              -- in meters
);

CREATE TABLE surfaces
(
    id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
    name varchar(255),
    created_at datetime,            -- currently not used
    updated_at datetime             -- currently not used
);

CREATE TABLE units
(
    id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
    name varchar(255),
    abbreviation varchar(255),
    base varchar(255),
    scale float,
    offset float,
    created_at datetime,            -- currently not used
    updated_at datetime             -- currently not used
);

CREATE TABLE weathers
(
    id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
    day_id integer,                 -- not used/obosolete
    temperature float,              -- in degrees Celsius
    sky integer,                    -- currently from 0 (= sunny) to 9 (=snow) 
    notes text,
    created_at datetime,            -- currently not used
    updated_at datetime,            -- currently not used
    day int                         -- julian day
);