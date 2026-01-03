from rtlsdr import RtlSdr

sdr = RtlSdr()
sdr.sample_rate = 2.4e6
sdr.center_freq = 100e6
sdr.gain = 'auto'

samples = sdr.read_samples(256*1024)
sdr.close()