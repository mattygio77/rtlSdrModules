#include <iostream>
#include <cstdio>

#include <rtl-sdr.h>

int main () {
    rtlsdr_dev_t* dev = nullptr;
    
    if (rtlsdr_open(&dev, 0) != 0) {
        printf("Could not connect to the radio\n");
        return -1;
    } else{
        printf("Connection Established\n");
    }
    
    rtlsdr_set_sample_rate(dev, 2400000);
    rtlsdr_set_center_freq(dev, 100000000);
    rtlsdr_set_tuner_gain_mode(dev, 0);
    
    uint8_t buffer[16384];
    int n_read;
    rtlsdr_read_sync(dev, buffer, sizeof(buffer), &n_read);
    
    rtlsdr_close(dev);
    
    printf("n_read: [%i]\n", n_read);
    for(size_t idx = 0; idx <= n_read; idx++){
        printf("Idx: [%zd], sample: [%u]\n", idx, buffer[idx]);
    }
}
