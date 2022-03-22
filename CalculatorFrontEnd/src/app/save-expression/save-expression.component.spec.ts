import { ComponentFixture, TestBed } from '@angular/core/testing';

import { SaveExpressionComponent } from './save-expression.component';

describe('SaveExpressionComponent', () => {
  let component: SaveExpressionComponent;
  let fixture: ComponentFixture<SaveExpressionComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ SaveExpressionComponent ]
    })
    .compileComponents();
  });

  beforeEach(() => {
    fixture = TestBed.createComponent(SaveExpressionComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
