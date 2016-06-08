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
  addi $sp, $sp, -44
  addi $sp, $sp, -4
  sw $ra, 0($sp)
  jal read
  lw $ra, 0($sp)
  addi $sp, $sp, 4
  lw $t0, -4($fp)
  move $t0, $v0
  move $a0, $t0
  lw $t1, -8($fp)
  move $t1, $a0
  move $a0, $t1
  lw $t2, -12($fp)
  move $t2, $a0
  li $a0, 0
  lw $t3, -16($fp)
  move $t3, $a0
  move $a1, $t2
  move $a2, $t3
  sw $t0, -4($fp)
  sw $t1, -8($fp)
  sw $t2, -12($fp)
  sw $t3, -16($fp)
  bgt $a1, $a2, label1
  j label2
label1:
  li $a0, 1
  lw $t0, -20($fp)
  move $t0, $a0
  move $a0, $t0
  addi $sp, $sp, -4
  sw $ra, 0($sp)
  jal write
  lw $ra, 0($sp)
  addi $sp, $sp, 4
  sw $t0, -20($fp)
  j label6
label2:
  lw $t0, -8($fp)
  move $a0, $t0
  lw $t1, -24($fp)
  move $t1, $a0
  li $a0, 0
  lw $t2, -28($fp)
  move $t2, $a0
  move $a1, $t1
  move $a2, $t2
  sw $t1, -24($fp)
  sw $t2, -28($fp)
  blt $a1, $a2, label4
  j label5
label4:
  li $a0, 1
  lw $t0, -32($fp)
  move $t0, $a0
  li $a1, 0
  move $a2, $t0
  sub $a0, $a1, $a2
  lw $t1, -36($fp)
  move $t1, $a0
  move $a0, $t1
  addi $sp, $sp, -4
  sw $ra, 0($sp)
  jal write
  lw $ra, 0($sp)
  addi $sp, $sp, 4
  sw $t0, -32($fp)
  sw $t1, -36($fp)
  j label6
label5:
  li $a0, 0
  lw $t0, -40($fp)
  move $t0, $a0
  move $a0, $t0
  addi $sp, $sp, -4
  sw $ra, 0($sp)
  jal write
  lw $ra, 0($sp)
  addi $sp, $sp, 4
  sw $t0, -40($fp)
label6:
  li $a0, 0
  lw $t0, -44($fp)
  move $t0, $a0
  move $sp, $fp
  move $v0, $t0
  sw $t0, -44($fp)
  jr $ra
