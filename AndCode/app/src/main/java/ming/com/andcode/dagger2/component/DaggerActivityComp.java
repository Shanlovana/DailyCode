package ming.com.andcode.dagger2.component;

import javax.inject.Singleton;

import dagger.Component;
import ming.com.andcode.dagger2.DaggerActivity;

import ming.com.andcode.dagger2.module.DaggeActivityModule;

import ming.com.andcode.dagger2.module.FlowerModule;
import ming.com.andcode.dagger2.scope.ActivityScope;


@ActivityScope
@Component(modules = {DaggeActivityModule.class},dependencies = PotComponent.class)
public interface DaggerActivityComp {
    void inject(DaggerActivity daggerActivity);
}
