`timescale 1ns / 1ps
module TimerCounter(
    input CLK,
    input [31:0] top_in,
    input [31:0] cmp_in,
    output PWM
    );
    reg [31:0] cnt;
    reg [31:0] top;
    reg [31:0] cmp;
    always @(posedge CLK)
    begin : CNT_MOD
        cnt <= cnt +1;
        if(cnt >= top)
            cnt <= 0;
    end

    assign PWM = (cnt < cmp);

    always @(posedge CLK)
    begin : TOP_MOD
        top <= top_in;
    end

    always @(posedge CLK)
    begin : CMP_MOD
        cmp <= cmp_in;
    end
endmodule