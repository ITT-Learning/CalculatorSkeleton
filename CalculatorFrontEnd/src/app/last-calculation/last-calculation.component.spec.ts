import { ComponentFixture, TestBed } from '@angular/core/testing';

import { LastCalculationComponent } from './last-calculation.component';

describe('LastCalculationComponent', () => {
  let component: LastCalculationComponent;
  let fixture: ComponentFixture<LastCalculationComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ LastCalculationComponent ]
    })
    .compileComponents();
  });

  beforeEach(() => {
    fixture = TestBed.createComponent(LastCalculationComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
