`timescale 1ns / 1ps
module MelodyScale(
    input CLK,
    input [7:0] BTN,
    output PWM
    );
    parameter DO_PERIOD = (125000000/262)-1;
    parameter RE_PERIOD = (125000000/294)-1;
    parameter MI_PERIOD = (125000000/330)-1;
    parameter PA_PERIOD = (125000000/349)-1;
    parameter SOL_PERIOD =(125000000/391)-1;
    parameter RA_PERIOD = (125000000/440)-1;
    parameter SI_PERIOD = (125000000/494)-1;
    parameter DO5_PERIOD = (125000000/523)-1;            
    reg [31:0] top_in;
    reg [31:0] cmp_in;
    TimerCounter TimerCounter_0(CLK, top_in, cmp_in, PWM );
    always @(BTN) begin
        if(BTN==128) begin
                top_in = DO5_PERIOD; cmp_in = DO5_PERIOD/2;
            end
        else if(BTN==64) begin
                top_in = SI_PERIOD; cmp_in = SI_PERIOD/2;        
            end
        else if(BTN==32) begin
                top_in = RA_PERIOD; cmp_in = RA_PERIOD/2;        
            end
        else if(BTN==16) begin
                top_in = SOL_PERIOD; cmp_in = SOL_PERIOD/2;  
            end
        else if(BTN==8) begin 
                top_in = PA_PERIOD; cmp_in = PA_PERIOD/2;
            end
        else if(BTN==4) begin
                top_in = MI_PERIOD; cmp_in = MI_PERIOD/2;
            end
        else if(BTN==2) begin
                top_in = RE_PERIOD; cmp_in = RE_PERIOD/2;
            end
        else if(BTN==1) begin
                top_in = DO_PERIOD; cmp_in = DO_PERIOD/2;
            end
        else begin
                top_in = 0; cmp_in = 0;
            end
    end
endmodule