module instruction_decoder(
    input [31:0] instruction,
    output [6:0] opcode,
    output [4:0] rd,
    output [4:0] rs1,
    output [11:0] imm
);
    assign opcode = instruction[6:0];
    assign rd = instruction[11:7];
    assign rs1 = instruction[19:15];
    assign imm = instruction[31:20];
endmodule

module execution_unit(
    input [6:0] opcode,
    input [4:0] rd,
    input [4:0] rs1,
    input [11:0] imm,
    output reg [31:0] result
);
    always @(*) begin
        if (opcode[1:0] == 2'b10) begin
            result = {20'b0, { {7'b0, {rs1}} + imm}};
        end
    end
endmodule

module control_logic(
    input [6:0] opcode,
    output reg [4:0] rd,
    output reg [4:0] rs1,
    output reg [11:0] imm
);
    always @(*) begin
        if (opcode[1:0] == 2'b10) begin
            rd  <= 5'b1;
            rs1 <= 5'b1;
            imm <= 12'b1;
        end
    end
endmodule

module cpu(
    input [31:0] instruction,
    output reg [31:0] result
);
    wire [6:0] opcode; 
    wire [4:0] rd;
    wire [4:0] rs1;
    wire [11:0] imm;

    instruction_decoder ID(
        .instruction(instruction),
        .opcode(opcode),
        .rd(rd),
        .rs1(rs1),
        .imm(imm)
    );

    execution_unit EU(
        .opcode(opcode),
        .rd(rd),
        .rs1(rs1),
        .imm(imm),
        .result(result)
    );

    control_logic CL(
        .opcode(opcode),
        .rd(rd),
        .rs1(rs1),
        .imm(imm)
    );
endmodule
