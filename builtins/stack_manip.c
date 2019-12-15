lit_code: /*: LIT ( lit ) ;*/
	ASMLABEL(lit_code);
	PUSH(sp) = tos;
	tos = *(cell_t *)ip++;
	next();

dup_code: /*: DUP ( dup ) ;*/
	ASMLABEL(dup_code);
	PUSH(sp) = tos;
	next();

drop_code: /*: DROP ( drop ) ;*/
	ASMLABEL(drop_code);
	tos = POP(sp);
	next();

swap_code: /*: SWAP ( swap ) ;*/
	ASMLABEL(swap_code);
	wp = (void **)sp[-1];
	sp[-1] = tos;
	tos = (cell_t)wp;
	next();

rot_code: /*: ROT ( rot ) ;*/
	ASMLABEL(rot_code);
	wp = (void **)sp[-2];
	sp[-2] = sp[-1];
	sp[-1] = tos;
	tos = (cell_t)wp;
	next();

over_code: /*: OVER ( over ) ;*/
	ASMLABEL(over_code);
	PUSH(sp) = tos;
	tos = sp[-2];
	next();

nip_code: /*: NIP ( nip ) ;*/
	ASMLABEL(nip_code);
	(void)POP(sp);
	next();

tuck_code: /*: TUCK ( tuck ) ;*/
	ASMLABEL(tuck_code);
	wp = (void **)sp[-1];
	sp[-1] = tos;
	PUSH(sp) = (cell_t)wp;
	next();

unrot_code: /*: -ROT ( unrot ) ;*/
	ASMLABEL(unrot_code);
	wp = (void **)sp[-1];
	sp[-1] = sp[-2];
	sp[-2] = tos;
	tos = (cell_t)wp;
	next();

qdup_code: /*: ?DUP ( qdup ) ;*/
	ASMLABEL(qdup_code);
	if (tos)
		PUSH(sp) = tos;
	next();
