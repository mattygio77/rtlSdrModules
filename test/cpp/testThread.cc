#include <iostream>
#include <vector>

#include <rtl-sdr.h>
#include <atomic>
#include <iostream>
#include <csignal>
#include <thread>
#include <functional>


using std::vector;

void dsp_worker()
{
    std::vector<uint8_t> block;

    while (true) {
        // rb.pop(block);
        continue;
        // Convert IQ, FFT, demod, etc.
    }
}

void rtlsdr_callback(unsigned char* buf, uint32_t len, void* ctx)
{
    // RingBuffer* rb = static_cast<RingBuffer*>(ctx);

    // if (!rb->push(buf, len)) {
    //     std::cerr << "OVERRUN: ring buffer full\n";
    // }
}


int main()
{
    rtlsdr_dev_t* dev = nullptr;

    if (rtlsdr_open(&dev, 0) != 0) {
        std::cerr << "Failed to open device\n";
        return 1;
    }

    rtlsdr_set_sample_rate(dev, 2400000);
    rtlsdr_set_center_freq(dev, 100000000);
    rtlsdr_set_tuner_gain_mode(dev, 0);

    std::cout << "Starting async read...\n";

    // RingBuffer rb(8 * 16384);  // 8 USB buffers
    std::thread dsp(dsp_worker);

    rtlsdr_read_async(dev, rtlsdr_callback, &rb, 0, 16384);

    rtlsdr_close(dev);
}