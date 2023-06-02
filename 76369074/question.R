library(terra)

# SPECIFY PROJECTIONS
pt.proj <- "+proj=longlat +datum=WGS84"
calc.proj <- "+proj=aea + lat_1=14.5 + lat_2=32.5 + lat_0=24.0 + lon_0=-105 +x_0=0 +y_0=0 + ellps =GRS80 +datum=NAD83 + units=m +no_defs"

# BUILDING SPATIAL VECTOR
# Fields
ids <- c("id00041130", "id00043728", "id00032757", "id00035604")
spp <- rep("Quercus_aerea", 4)
lats <- c(27.4, 25.1, 26.9, 28.2)
longs <- c(-108, -106, -107, -107)
spat_points <- cbind.data.frame(ids, spp, lats, longs)
# Convert to spatial vector
spat_vect <- vect(spat_points, geom=c("longs", "lats"), crs=pt.proj, keepgeom=FALSE)

# PROJECT FUNCTION (CRASHING)
spat_vect.calc <- project(spat_vect,calc.proj)
