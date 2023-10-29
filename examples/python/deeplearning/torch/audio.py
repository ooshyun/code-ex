import os
import torch
import soundfile as sf
import torchaudio as ta
import matplotlib.pyplot as plt
from torchaudio.utils import download_asset

if __name__ == '__main__':
    print(torch.__version__)
    print(ta.__version__)
    print(str(ta.list_audio_backends()))
    # Save audio file as wav
    SAMPLE_WAV = download_asset("tutorial-assets/Lab41-SRI-VOiCES-src-sp0307-ch127535-sg0042.wav")
    metadata = ta.info(SAMPLE_WAV)
    print(metadata)
    ta.save('./audio.wav', torch.rand(1, 16000), 16000)

    # Load audio file
    wav, sr = ta.load('./audio.wav')
    os.remove('./audio.wav')