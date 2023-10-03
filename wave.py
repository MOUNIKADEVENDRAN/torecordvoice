import numpy as np
import matplotlib.pyplot as plt
import wavw
def plot_waveform(filename):
  wf=wave.open(filename,'rb')
  signal=wf.readframes(-1)
  signal=np.frombuffer(signal,stype=np.int16)
  time=np.linespace(0,len(signal)
  plt.figure()
  plt.plot(time,sigal)
  plt.xlabel('Time(s)')
  plt.ylabel('Amplitude')
  plt.title('recorded sound')
  plt.grid()
  plt.show()
  if __name__=='__main__':
    filename='audio.c'
    plot_waveform(filename)
