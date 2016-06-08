.data
_prompt: .asciiz "Enter an integer:"
_ret: .asciiz "\n"
.globl main
.text
read:
  li $v0, 4
  la $a0, _prompt
  syscall
  li $v0, 5
  syscall
  jr $ra

write:
  li $v0, 1
  syscall
  li $v0, 4
  la $a0, _ret
  syscall
  move $v0, $0
  jr $ra

main:
  move $fp, $sp
  addi $sp, $sp, -228
  li $a0, 0
  lw $t0, -4($fp)
  move $t0, $a0
  move $a0, $t0
  lw $t1, -8($fp)
  move $t1, $a0
  li $a0, 1
  lw $t2, -12($fp)
  move $t2, $a0
  move $a0, $t2
  lw $t3, -16($fp)
  move $t3, $a0
  move $a0, $t1
  lw $t4, -20($fp)
  move $t4, $a0
  move $a0, $t3
  lw $t5, -24($fp)
  move $t5, $a0
  move $a1, $t4
  move $a2, $t5
  add $a0, $a1, $a2
  lw $t6, -28($fp)
  move $t6, $a0
  move $a0, $t6
  lw $t7, -32($fp)
  move $t7, $a0
  move $a0, $t7
  sw $t0, -4($fp)
  lw $t0, -36($fp)
  move $t0, $a0
  move $a0, $t1
  sw $t0, -36($fp)
  lw $t0, -40($fp)
  move $t0, $a0
  sw $t0, -40($fp)
  lw $t0, -36($fp)
  move $a1, $t0
  lw $t0, -40($fp)
  move $a2, $t0
  sub $a0, $a1, $a2
  lw $t0, -44($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -44($fp)
  lw $t0, -48($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -48($fp)
  lw $t0, -52($fp)
  move $t0, $a0
  li $a0, 5
  sw $t0, -52($fp)
  lw $t0, -56($fp)
  move $t0, $a0
  sw $t0, -56($fp)
  lw $t0, -52($fp)
  move $a1, $t0
  lw $t0, -56($fp)
  move $a2, $t0
  add $a0, $a1, $a2
  lw $t0, -60($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -60($fp)
  lw $t0, -64($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -64($fp)
  lw $t0, -68($fp)
  move $t0, $a0
  li $a0, 3
  sw $t0, -68($fp)
  lw $t0, -72($fp)
  move $t0, $a0
  sw $t0, -72($fp)
  lw $t0, -68($fp)
  move $a1, $t0
  lw $t0, -72($fp)
  move $a2, $t0
  sub $a0, $a1, $a2
  lw $t0, -76($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -76($fp)
  lw $t0, -80($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -80($fp)
  lw $t0, -84($fp)
  move $t0, $a0
  move $a0, $t1
  sw $t0, -84($fp)
  lw $t0, -88($fp)
  move $t0, $a0
  sw $t0, -88($fp)
  lw $t0, -84($fp)
  move $a1, $t0
  lw $t0, -88($fp)
  move $a2, $t0
  mul $a0, $a1, $a2
  lw $t0, -92($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -92($fp)
  lw $t0, -96($fp)
  move $t0, $a0
  sw $t0, -96($fp)
  lw $t0, -80($fp)
  move $a0, $t0
  lw $t0, -100($fp)
  move $t0, $a0
  move $a0, $t3
  sw $t0, -100($fp)
  lw $t0, -104($fp)
  move $t0, $a0
  sw $t0, -104($fp)
  lw $t0, -100($fp)
  move $a1, $t0
  lw $t0, -104($fp)
  move $a2, $t0
  mul $a0, $a1, $a2
  lw $t0, -108($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -108($fp)
  lw $t0, -112($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -112($fp)
  lw $t0, -116($fp)
  move $t0, $a0
  move $a0, $t7
  sw $t0, -116($fp)
  lw $t0, -120($fp)
  move $t0, $a0
  sw $t0, -120($fp)
  lw $t0, -116($fp)
  move $a1, $t0
  lw $t0, -120($fp)
  move $a2, $t0
  div $a1, $a2
  mflo $a0
  lw $t0, -124($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -124($fp)
  lw $t0, -128($fp)
  move $t0, $a0
  sw $t0, -128($fp)
  lw $t0, -96($fp)
  move $a0, $t0
  lw $t0, -132($fp)
  move $t0, $a0
  sw $t0, -132($fp)
  lw $t0, -112($fp)
  move $a0, $t0
  lw $t0, -136($fp)
  move $t0, $a0
  sw $t0, -136($fp)
  lw $t0, -132($fp)
  move $a1, $t0
  lw $t0, -136($fp)
  move $a2, $t0
  add $a0, $a1, $a2
  lw $t0, -140($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -140($fp)
  lw $t0, -144($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -144($fp)
  lw $t0, -148($fp)
  move $t0, $a0
  sw $t0, -148($fp)
  lw $t0, -128($fp)
  move $a0, $t0
  lw $t0, -152($fp)
  move $t0, $a0
  sw $t0, -152($fp)
  lw $t0, -148($fp)
  move $a1, $t0
  lw $t0, -152($fp)
  move $a2, $t0
  add $a0, $a1, $a2
  lw $t0, -156($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -156($fp)
  lw $t0, -160($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -160($fp)
  lw $t0, -164($fp)
  move $t0, $a0
  li $a0, 2
  sw $t0, -164($fp)
  lw $t0, -168($fp)
  move $t0, $a0
  sw $t0, -168($fp)
  lw $t0, -164($fp)
  move $a1, $t0
  lw $t0, -168($fp)
  move $a2, $t0
  mul $a0, $a1, $a2
  lw $t0, -172($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -172($fp)
  lw $t0, -176($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -176($fp)
  lw $t0, -180($fp)
  move $t0, $a0
  li $a0, 3
  sw $t0, -180($fp)
  lw $t0, -184($fp)
  move $t0, $a0
  sw $t0, -184($fp)
  lw $t0, -180($fp)
  move $a1, $t0
  lw $t0, -184($fp)
  move $a2, $t0
  div $a1, $a2
  mflo $a0
  lw $t0, -188($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -188($fp)
  lw $t0, -192($fp)
  move $t0, $a0
  sw $t0, -192($fp)
  lw $t0, -176($fp)
  move $a0, $t0
  lw $t0, -196($fp)
  move $t0, $a0
  sw $t0, -196($fp)
  lw $t0, -192($fp)
  move $a0, $t0
  lw $t0, -200($fp)
  move $t0, $a0
  sw $t0, -200($fp)
  lw $t0, -196($fp)
  move $a1, $t0
  lw $t0, -200($fp)
  move $a2, $t0
  add $a0, $a1, $a2
  lw $t0, -204($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -204($fp)
  lw $t0, -208($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -208($fp)
  lw $t0, -212($fp)
  move $t0, $a0
  li $a1, 0
  move $a2, $t0
  sub $a0, $a1, $a2
  sw $t0, -212($fp)
  lw $t0, -216($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -216($fp)
  lw $t0, -220($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -220($fp)
  lw $t0, -224($fp)
  move $t0, $a0
  move $a0, $t0
  addi $sp, $sp, -4
  sw $ra, 0($sp)
  jal write
  lw $ra, 0($sp)
  addi $sp, $sp, 4
  li $a0, 0
  sw $t0, -224($fp)
  lw $t0, -228($fp)
  move $t0, $a0
  move $sp, $fp
  move $v0, $t0
  sw $t1, -8($fp)
  sw $t2, -12($fp)
  sw $t3, -16($fp)
  sw $t4, -20($fp)
  sw $t5, -24($fp)
  sw $t6, -28($fp)
  sw $t7, -32($fp)
  sw $t0, -228($fp)
  jr $ra
