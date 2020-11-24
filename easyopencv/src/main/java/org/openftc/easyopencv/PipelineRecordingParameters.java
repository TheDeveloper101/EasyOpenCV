/*
 * Copyright (c) 2020 OpenFTC Team
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

package org.openftc.easyopencv;

import android.media.MediaRecorder;

import java.text.SimpleDateFormat;

public class PipelineRecordingParameters
{
    public final String path;
    public final int encoder;
    public final int outputformat;
    public final int bitrate;
    public final int frameRate;

    public PipelineRecordingParameters(int outputformat, int encoder, int frameRate, int bitrate, String path)
    {
        this.outputformat = outputformat;
        this.encoder = encoder;
        this.frameRate = frameRate;
        this.bitrate = bitrate;
        this.path = path;
    }

    public static class Builder
    {
        private String path = "/sdcard/EasyOpenCV/pipeline_recording_"+System.currentTimeMillis()+".mp4";
        private int encoder = MediaRecorder.VideoEncoder.H264;
        private int outputformat = MediaRecorder.OutputFormat.MPEG_4;
        private int bitrate = 4000000;
        private int frameRate = 30;

        public Builder setPath(String path)
        {
            this.path = path;
            return this;
        }

        public Builder setEncoder(int encoder)
        {
            this.encoder = encoder;
            return this;
        }

        public Builder setOutputFormat(int outputformat)
        {
            this.outputformat = outputformat;
            return this;
        }

        public Builder setBitrate(int bitrate)
        {
            this.bitrate = bitrate;
            return this;
        }

        public Builder setFrameRate(int frameRate)
        {
            this.frameRate = frameRate;
            return this;
        }

        public PipelineRecordingParameters build()
        {
            return new PipelineRecordingParameters(outputformat, encoder, frameRate, bitrate, path);
        }
    }
}
