#ifndef EVM_EVM_H
#define EVM_EVM_H


typedef enum {
	EVM_OP_STOP = 0x00,
	EVM_OP_ADD,
	EVM_OP_MUL,
	EVM_OP_SUB,
	EVM_OP_DIV,
	EVM_OP_SDIV,
	EVM_OP_MOD,
	EVM_OP_SMOD,
	EVM_OP_ADDMOD,
	EVM_OP_MULMOD,
	EVM_OP_EXP,
	EVM_OP_SIGNEXTEND,

	EVM_OP_LT = 0x10,
	EVM_OP_GT,
	EVM_OP_SLT,
	EVM_OP_SGT,
	EVM_OP_EQ,
	EVM_OP_ISZERO,
	EVM_OP_AND,
	EVM_OP_OR,
	EVM_OP_XOR,
	EVM_OP_NOT,
	EVM_OP_BYTE,
	EVM_OP_SHA3 = 0x20,

	EVM_OP_ADDRESS = 0x30,
	EVM_OP_BALANCE,
	EVM_OP_ORIGIN,
	EVM_OP_CALLER,
	EVM_OP_CALLVALUE,
	EVM_OP_CALLDATALOAD,
	EVM_OP_CALLDATASIZE,
	EVM_OP_CALLDATACOPY,
	EVM_OP_CODESIZE,
	EVM_OP_CODECOPY,
	EVM_OP_GASPRICE,
	EVM_OP_EXTCODESIZE,
	EVM_OP_EXTCODECOPY,

	EVM_OP_BLOCKHASH = 0x40,
	EVM_OP_COINBASE,
	EVM_OP_TIMESTAMP,
	EVM_OP_NUMBER,
	EVM_OP_DIFFICULTY,
	EVM_OP_GASLIMIT,

	EVM_OP_POP = 0x50,
	EVM_OP_MLOAD,
	EVM_OP_MSTORE,
	EVM_OP_MSTORE8,
	EVM_OP_SLOAD,
	EVM_OP_SSTORE,
	EVM_OP_JUMP,
	EVM_OP_JUMPI,
	EVM_OP_PC,
	EVM_OP_MSIZE,
	EVM_OP_GAS,
	EVM_OP_JUMPDEST,

	EVM_OP_PUSH1 = 0x60,
	EVM_OP_PUSH2,
	EVM_OP_PUSH3,
	EVM_OP_PUSH4,
	EVM_OP_PUSH5,
	EVM_OP_PUSH6,
	EVM_OP_PUSH7,
	EVM_OP_PUSH8,
	EVM_OP_PUSH9,
	EVM_OP_PUSH10,
	EVM_OP_PUSH11,
	EVM_OP_PUSH12,
	EVM_OP_PUSH13,
	EVM_OP_PUSH14,
	EVM_OP_PUSH15,
	EVM_OP_PUSH16,
	EVM_OP_PUSH17,
	EVM_OP_PUSH18,
	EVM_OP_PUSH19,
	EVM_OP_PUSH20,
	EVM_OP_PUSH21,
	EVM_OP_PUSH22,
	EVM_OP_PUSH23,
	EVM_OP_PUSH24,
	EVM_OP_PUSH25,
	EVM_OP_PUSH26,
	EVM_OP_PUSH27,
	EVM_OP_PUSH28,
	EVM_OP_PUSH29,
	EVM_OP_PUSH30,
	EVM_OP_PUSH31,
	EVM_OP_PUSH32,
	EVM_OP_DUP1,
	EVM_OP_DUP2,
	EVM_OP_DUP3,
	EVM_OP_DUP4,
	EVM_OP_DUP5,
	EVM_OP_DUP6,
	EVM_OP_DUP7,
	EVM_OP_DUP8,
	EVM_OP_DUP9,
	EVM_OP_DUP10,
	EVM_OP_DUP11,
	EVM_OP_DUP12,
	EVM_OP_DUP13,
	EVM_OP_DUP14,
	EVM_OP_DUP15,
	EVM_OP_DUP16,
	EVM_OP_SWAP1,
	EVM_OP_SWAP2,
	EVM_OP_SWAP3,
	EVM_OP_SWAP4,
	EVM_OP_SWAP5,
	EVM_OP_SWAP6,
	EVM_OP_SWAP7,
	EVM_OP_SWAP8,
	EVM_OP_SWAP9,
	EVM_OP_SWAP10,
	EVM_OP_SWAP11,
	EVM_OP_SWAP12,
	EVM_OP_SWAP13,
	EVM_OP_SWAP14,
	EVM_OP_SWAP15,
	EVM_OP_SWAP16,

	EVM_OP_LOG0 = 0xa0,
	EVM_OP_LOG1,
	EVM_OP_LOG2,
	EVM_OP_LOG3,
	EVM_OP_LOG4,

	EVM_OP_CREATE = 0xf0,
	EVM_OP_CALL,
	EVM_OP_CALLCODE,
	EVM_OP_RETURN,
	EVM_OP_DELEGATECALL,
	EVM_OP_STATICCALL = 0xfa,
	EVM_OP_REVERT = 0xfd,
	EVM_OP_SELFDESTRUCT = 0xff
} EvmOpcodes;

typedef struct EvmOp {
	EvmOpcodes op;
	int len;
	uint64_t imm;
	const char *txt;
	char txt_buf[32];
} EvmOp;

typedef struct {
	const char *txt;
	int len;
} EvmOpDef;


static EvmOpDef opcodes[256] = {
	[EVM_OP_STOP] = { "stop", 1 },
	[EVM_OP_ADD] = { "add", 1 },
	[EVM_OP_MUL] = { "mul", 1 },
	[EVM_OP_SUB] = { "sub", 1 },
	[EVM_OP_DIV] = { "div", 1 },
	[EVM_OP_SDIV] = { "sdiv", 1 },
	[EVM_OP_MOD] = { "mod", 1 },
	[EVM_OP_SMOD] = { "smod", 1 },
	[EVM_OP_ADDMOD] = { "addmod", 1 },
	[EVM_OP_MULMOD] = { "mulmod", 1 },
	[EVM_OP_EXP] = { "exp", 1 },
	[EVM_OP_SIGNEXTEND] = { "signextend", 1 },
	[EVM_OP_LT] = { "lt", 1 },
	[EVM_OP_GT] = { "gt", 1 },
	[EVM_OP_SLT] = { "slt", 1 },
	[EVM_OP_SGT] = { "sgt", 1 },
	[EVM_OP_EQ] = { "eq", 1 },
	[EVM_OP_ISZERO] = { "iszero", 1 },
	[EVM_OP_AND] = { "and", 1 },
	[EVM_OP_OR] = { "or", 1 },
	[EVM_OP_XOR] = { "xor", 1 },
	[EVM_OP_NOT] = { "not", 1 },
	[EVM_OP_BYTE] = { "byte", 1 },
	[EVM_OP_SHA3] = { "sha3", 1 },
	[EVM_OP_ADDRESS] = { "address", 1 },
	[EVM_OP_BALANCE] = { "balance", 1 },
	[EVM_OP_ORIGIN] = { "origin", 1 },
	[EVM_OP_CALLER] = { "caller", 1 },
	[EVM_OP_CALLVALUE] = { "callvalue", 1 },
	[EVM_OP_CALLDATALOAD] = { "calldataload", 1 },
	[EVM_OP_CALLDATASIZE] = { "calldatasize", 1 },
	[EVM_OP_CALLDATACOPY] = { "calldatacopy", 1 },
	[EVM_OP_CODESIZE] = { "codesize", 1 },
	[EVM_OP_CODECOPY] = { "codecopy", 1 },
	[EVM_OP_GASPRICE] = { "gasprice", 1 },
	[EVM_OP_EXTCODESIZE] = { "extcodesize", 1 },
	[EVM_OP_EXTCODECOPY] = { "extcodecopy", 1 },
	[EVM_OP_BLOCKHASH] = { "blockhash", 1 },
	[EVM_OP_COINBASE] = { "coinbase", 1 },
	[EVM_OP_TIMESTAMP] = { "timestamp", 1 },
	[EVM_OP_NUMBER] = { "number", 1 },
	[EVM_OP_DIFFICULTY] = { "difficulty", 1 },
	[EVM_OP_GASLIMIT] = { "gaslimit", 1 },
	[EVM_OP_POP] = { "pop", 1 },
	[EVM_OP_MLOAD] = { "mload", 1 },
	[EVM_OP_MSTORE] = { "mstore", 1 },
	[EVM_OP_MSTORE8] = { "mstore8", 1 },
	[EVM_OP_SLOAD] = { "sload", 1 },
	[EVM_OP_SSTORE] = { "sstore", 1 },
	[EVM_OP_JUMP] = { "jump", 1 },
	[EVM_OP_JUMPI] = { "jumpi", 1 },
	[EVM_OP_PC] = { "pc", 1 },
	[EVM_OP_MSIZE] = { "msize", 1 },
	[EVM_OP_GAS] = { "gas", 1 },
	[EVM_OP_JUMPDEST] = { "jumpdest", 1 },
	// ....
	[EVM_OP_CREATE] = { "create", 1 },
	[EVM_OP_CALL] = { "call", 1 },
	[EVM_OP_CALLCODE] = { "callcode", 1 },
	[EVM_OP_RETURN] = { "return", 1 },
	[EVM_OP_DELEGATECALL] = { "delegatecall", 1 },
	[EVM_OP_STATICCALL] = { "staticcall", 1 },
	[EVM_OP_REVERT] = { "revert", 1 },
	[EVM_OP_SELFDESTRUCT] = { "selfdestruct", 1 },
};

int evm_dis(EvmOp *op, const unsigned char *buf, int buf_len);
int evm_asm(const char *str, unsigned char *buf, int buf_len);

#endif	/* EVM_EVM_H */
