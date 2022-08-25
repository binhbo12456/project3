while(x != 0)
{
scanf("%d", &x);
switch (x)
{
printf("input '2' to...\n");
printf("input '3' to...\n");
printf("input '4' to...\n");
printf("input '5' to...\n");
printf("input '6' to...\n");
case 1:
head = Enqueue(head);
break;
case 2:
head1 = spisokMagazinovScenoiMensheiZadannoi(head, head1);
break;
case 3:
head1 = udalenieElementa(head1);
break;
case 4:
head1 = addNewMagazin(head1);
break;
case 5:
head1 = addNewMagazin(head1);
break;
case 6:
printToTheFile(head);
break;

}
}