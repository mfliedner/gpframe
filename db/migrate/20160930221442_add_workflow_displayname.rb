class AddWorkflowDisplayname < ActiveRecord::Migration
  def change
    add_column :workflows, :script, :string
  end
end
