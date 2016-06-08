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

bfunc_abc:
  move $fp, $sp
  addi $sp, $sp, -632
  sw $a0, -4($fp)
  sw $a1, -8($fp)
  li $a0, 1
  lw $t0, -412($fp)
  move $t0, $a0
  move $a0, $t0
  lw $t1, -416($fp)
  move $t1, $a0
  sw $t0, -412($fp)
  sw $t1, -416($fp)
label1:
  lw $t0, -416($fp)
  move $a0, $t0
  lw $t1, -420($fp)
  move $t1, $a0
  lw $t2, -4($fp)
  move $a0, $t2
  lw $t3, -424($fp)
  move $t3, $a0
  move $a1, $t1
  move $a2, $t3
  sw $t1, -420($fp)
  sw $t3, -424($fp)
  ble $a1, $a2, label2
  j label3
label2:
  addi $t0, $fp, -408
  move $a0, $t0
  lw $t1, -428($fp)
  move $t1, $a0
  lw $t2, -416($fp)
  move $a0, $t2
  lw $t3, -432($fp)
  move $t3, $a0
  move $a1, $t3
  li $a2, 4
  mul $a0, $a1, $a2
  lw $t4, -436($fp)
  move $t4, $a0
  move $a1, $t1
  move $a2, $t4
  add $a0, $a1, $a2
  lw $t5, -440($fp)
  move $t5, $a0
  li $a0, 1
  lw $t6, -444($fp)
  move $t6, $a0
  move $a0, $t6
  sw $a0, 0($t5)
  move $a0, $t2
  lw $t7, -448($fp)
  move $t7, $a0
  li $a0, 1
  lw $t0, -452($fp)
  move $t0, $a0
  move $a1, $t7
  move $a2, $t0
  add $a0, $a1, $a2
  sw $t0, -452($fp)
  lw $t0, -456($fp)
  move $t0, $a0
  move $a0, $t0
  move $t2, $a0
  sw $t2, -416($fp)
  sw $t1, -428($fp)
  sw $t3, -432($fp)
  sw $t4, -436($fp)
  sw $t5, -440($fp)
  sw $t6, -444($fp)
  sw $t7, -448($fp)
  sw $t0, -456($fp)
  j label1
label3:
  li $a0, 0
  lw $t0, -460($fp)
  move $t0, $a0
  move $a0, $t0
  lw $t1, -464($fp)
  move $t1, $a0
  li $a0, 0
  lw $t2, -468($fp)
  move $t2, $a0
  move $a0, $t2
  lw $t3, -472($fp)
  move $t3, $a0
  li $a0, 1
  lw $t4, -476($fp)
  move $t4, $a0
  move $a0, $t4
  lw $t5, -416($fp)
  move $t5, $a0
  sw $t5, -416($fp)
  sw $t0, -460($fp)
  sw $t1, -464($fp)
  sw $t2, -468($fp)
  sw $t3, -472($fp)
  sw $t4, -476($fp)
label4:
  lw $t0, -416($fp)
  move $a0, $t0
  lw $t1, -480($fp)
  move $t1, $a0
  lw $t2, -4($fp)
  move $a0, $t2
  lw $t3, -484($fp)
  move $t3, $a0
  move $a1, $t1
  move $a2, $t3
  sw $t1, -480($fp)
  sw $t3, -484($fp)
  ble $a1, $a2, label5
  j label6
label5:
  addi $t0, $fp, -408
  move $a0, $t0
  lw $t1, -488($fp)
  move $t1, $a0
  lw $t2, -416($fp)
  move $a0, $t2
  lw $t3, -492($fp)
  move $t3, $a0
  move $a1, $t3
  li $a2, 4
  mul $a0, $a1, $a2
  lw $t4, -496($fp)
  move $t4, $a0
  move $a1, $t1
  move $a2, $t4
  add $a0, $a1, $a2
  lw $t5, -500($fp)
  move $t5, $a0
  lw $a0, 0($t5)
  lw $t6, -504($fp)
  move $t6, $a0
  li $a0, 1
  lw $t7, -508($fp)
  move $t7, $a0
  move $a1, $t6
  move $a2, $t7
  sw $t1, -488($fp)
  sw $t3, -492($fp)
  sw $t4, -496($fp)
  sw $t5, -500($fp)
  sw $t6, -504($fp)
  sw $t7, -508($fp)
  beq $a1, $a2, label7
  j label12
label7:
  lw $t0, -464($fp)
  move $a0, $t0
  lw $t1, -512($fp)
  move $t1, $a0
  addi $t2, $fp, -408
  move $a0, $t2
  lw $t3, -516($fp)
  move $t3, $a0
  lw $t4, -416($fp)
  move $a0, $t4
  lw $t5, -520($fp)
  move $t5, $a0
  move $a1, $t5
  li $a2, 4
  mul $a0, $a1, $a2
  lw $t6, -524($fp)
  move $t6, $a0
  move $a1, $t3
  move $a2, $t6
  add $a0, $a1, $a2
  lw $t7, -528($fp)
  move $t7, $a0
  lw $a0, 0($t7)
  lw $t0, -532($fp)
  move $t0, $a0
  move $a1, $t1
  move $a2, $t0
  add $a0, $a1, $a2
  sw $t0, -532($fp)
  lw $t0, -536($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -536($fp)
  lw $t0, -464($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -464($fp)
  lw $t0, -540($fp)
  move $t0, $a0
  sw $t0, -540($fp)
  lw $t0, -8($fp)
  move $a0, $t0
  lw $t0, -544($fp)
  move $t0, $a0
  sw $t0, -544($fp)
  lw $t0, -540($fp)
  move $a1, $t0
  lw $t0, -544($fp)
  move $a2, $t0
  sw $t1, -512($fp)
  sw $t3, -516($fp)
  sw $t5, -520($fp)
  sw $t6, -524($fp)
  sw $t7, -528($fp)
  beq $a1, $a2, label9
  j label10
label9:
  lw $t0, -416($fp)
  move $a0, $t0
  lw $t1, -548($fp)
  move $t1, $a0
  move $a0, $t1
  addi $sp, $sp, -4
  sw $ra, 0($sp)
  jal write
  lw $ra, 0($sp)
  addi $sp, $sp, 4
  li $a0, 0
  lw $t2, -552($fp)
  move $t2, $a0
  move $a0, $t2
  lw $t3, -464($fp)
  move $t3, $a0
  addi $t4, $fp, -408
  move $a0, $t4
  lw $t5, -556($fp)
  move $t5, $a0
  move $a0, $t0
  lw $t6, -560($fp)
  move $t6, $a0
  move $a1, $t6
  li $a2, 4
  mul $a0, $a1, $a2
  lw $t7, -564($fp)
  move $t7, $a0
  move $a1, $t5
  move $a2, $t7
  add $a0, $a1, $a2
  lw $t0, -568($fp)
  move $t0, $a0
  li $a0, 0
  sw $t0, -568($fp)
  lw $t0, -572($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -572($fp)
  lw $t0, -568($fp)
  sw $a0, 0($t0)
  lw $t0, -472($fp)
  move $a0, $t0
  lw $t0, -576($fp)
  move $t0, $a0
  li $a0, 1
  sw $t0, -576($fp)
  lw $t0, -580($fp)
  move $t0, $a0
  sw $t0, -580($fp)
  lw $t0, -576($fp)
  move $a1, $t0
  lw $t0, -580($fp)
  move $a2, $t0
  add $a0, $a1, $a2
  lw $t0, -584($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -584($fp)
  lw $t0, -472($fp)
  move $t0, $a0
  sw $t3, -464($fp)
  sw $t0, -472($fp)
  sw $t1, -548($fp)
  sw $t2, -552($fp)
  sw $t5, -556($fp)
  sw $t6, -560($fp)
  sw $t7, -564($fp)
label10:
  lw $t0, -472($fp)
  move $a0, $t0
  lw $t1, -588($fp)
  move $t1, $a0
  lw $t2, -4($fp)
  move $a0, $t2
  lw $t3, -592($fp)
  move $t3, $a0
  move $a1, $t1
  move $a2, $t3
  sw $t1, -588($fp)
  sw $t3, -592($fp)
  beq $a1, $a2, label11
  j label12
label11:
  lw $t0, -416($fp)
  move $a0, $t0
  lw $t1, -596($fp)
  move $t1, $a0
  move $a0, $t1
  lw $t2, -600($fp)
  move $t2, $a0
  li $a0, 0
  lw $t3, -604($fp)
  move $t3, $a0
  move $sp, $fp
  move $v0, $t3
  sw $t1, -596($fp)
  sw $t2, -600($fp)
  sw $t3, -604($fp)
  jr $ra
label12:
  lw $t0, -416($fp)
  move $a0, $t0
  lw $t1, -608($fp)
  move $t1, $a0
  lw $t2, -4($fp)
  move $a0, $t2
  lw $t3, -612($fp)
  move $t3, $a0
  move $a1, $t1
  move $a2, $t3
  sw $t1, -608($fp)
  sw $t3, -612($fp)
  beq $a1, $a2, label13
  j label14
label13:
  li $a0, 0
  lw $t0, -616($fp)
  move $t0, $a0
  move $a0, $t0
  lw $t1, -416($fp)
  move $t1, $a0
  sw $t1, -416($fp)
  sw $t0, -616($fp)
label14:
  lw $t0, -416($fp)
  move $a0, $t0
  lw $t1, -620($fp)
  move $t1, $a0
  li $a0, 1
  lw $t2, -624($fp)
  move $t2, $a0
  move $a1, $t1
  move $a2, $t2
  add $a0, $a1, $a2
  lw $t3, -628($fp)
  move $t3, $a0
  move $a0, $t3
  move $t0, $a0
  sw $t0, -416($fp)
  sw $t1, -620($fp)
  sw $t2, -624($fp)
  sw $t3, -628($fp)
  j label4
label6:
  li $a0, 0
  lw $t0, -632($fp)
  move $t0, $a0
  move $sp, $fp
  move $v0, $t0
  sw $t0, -632($fp)
  jr $ra

main:
  move $fp, $sp
  addi $sp, $sp, -32
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
  addi $sp, $sp, -4
  sw $ra, 0($sp)
  jal read
  lw $ra, 0($sp)
  addi $sp, $sp, 4
  lw $t2, -12($fp)
  move $t2, $v0
  move $a0, $t2
  lw $t3, -16($fp)
  move $t3, $a0
  move $a0, $t1
  lw $t4, -20($fp)
  move $t4, $a0
  move $a0, $t3
  lw $t5, -24($fp)
  move $t5, $a0
  move $a1, $t5
  move $a0, $t4
  addi $sp, $sp, -40
  sw $ra, 36($sp)
  sw $fp, 32($sp)
  sw $t0, 28($sp)
  sw $t1, 24($sp)
  sw $t2, 20($sp)
  sw $t3, 16($sp)
  sw $t4, 12($sp)
  sw $t5, 8($sp)
  sw $t6, 4($sp)
  sw $t7, 0($sp)
  jal bfunc_abc
  lw $ra, 36($sp)
  lw $fp, 32($sp)
  lw $t0, 28($sp)
  lw $t1, 24($sp)
  lw $t2, 20($sp)
  lw $t3, 16($sp)
  lw $t4, 12($sp)
  lw $t5, 8($sp)
  lw $t6, 4($sp)
  lw $t7, 0($sp)
  addi $sp, $sp, 40
  lw $t6, -28($fp)
  move $t6, $v0
  li $a0, 0
  lw $t7, -32($fp)
  move $t7, $a0
  move $sp, $fp
  move $v0, $t7
  sw $t0, -4($fp)
  sw $t1, -8($fp)
  sw $t2, -12($fp)
  sw $t3, -16($fp)
  sw $t4, -20($fp)
  sw $t5, -24($fp)
  sw $t6, -28($fp)
  sw $t7, -32($fp)
  jr $ra
