from astropy.io import fits
import numpy as np
import os

path = os.environ["RELTRANS_TABLES"]

fits_image_filename = path + '/xillverCp_v3.4.fits'
new_table = 'xillverCp_v3.4_normalised.fits'

print ('This script take the table '+fits_image_filename)
print('and renormalise it, creating a new table called ' + new_table)

print('Reading and modifying the table...')
with fits.open(fits_image_filename) as hdul:
    spectra_extension = hdul['SPECTRA'].data
    length = len(spectra_extension.field(0))
    logxi = spectra_extension.field(0)[:,2].reshape(length,1) # logxi ionisation values of the spectra
    logne = spectra_extension.field(0)[:,4].reshape(length,1) #  logne density values of the spectra
    # data = spectra_extension.field(1)
    # norm = 10**(logxi + logne - 15)
    # spectra_extension.field(1) / norm

    spectra_extension['INTPSPEC'] = spectra_extension['INTPSPEC'] / 10**(logxi + logne - 15)
    hdul.writeto(path+'/'+new_table)

print('Finished')
