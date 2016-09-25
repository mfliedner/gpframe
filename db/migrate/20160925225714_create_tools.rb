class CreateTools < ActiveRecord::Migration
  def change
    create_table :tools do |t|
      t.string :executable
      t.string :help
      t.string :name
      t.string :tooltip
      t.text :parameters

      t.timestamps null: false
    end
  end
end
