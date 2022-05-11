
#RVER = `Rscript -e 'cat(R.Version()$$major)'`
RVER = `Rscript -e 'cat(gsub("(\\\\.\\\\d)?$$", "", format(getRversion())))'`

SOMEDIR = "/opt/foo/bar/"${RVER}"/some/more"

all:
	@echo Using ${SOMEDIR}
