`timescale 1ns / 1ps
module tb_AutoPlay();
    reg CLK=1;
    reg BTN = 0;
    reg BTN_s = 1;
    wire PWM;
    AutoPlay AutoPlay_0(CLK, BTN, BTN_s, PWM);    
    always begin
        #4 CLK= ~CLK;
    end
    initial begin
        #1000 BTN = 0;
        #1000 BTN = 1;
    end
endmodule